import os
from glob import glob
from datetime import datetime

import requests
import pandas as pd


#our index -> NOAA index
NOAAIndex = {
        1:24,
        2:25,
        3:5,
        4:6,
        5:27,
        6:23,
        7:26,
        8:7,
        9:11,
        10:13,
        11:14,
        12:15,
        13:16,
        14:17,
        15:18,
        16:19,
        17:21,
        18:22,
        19:8,
        20:9,
        21:10,
        22:1,
        23:3,
        24:2,
        25:4, 
        26:12, #Kiev
        27:20 #Sevastopol
}

def preprocess_raw_data(line : str):
    if '/' in line:  
        return None    
    line = line.replace(' ', ',',2)    
    return (line + '\n')

def clear_dir(directory : str, index : int):    
    for file in glob(os.path.join(directory, "province-{}*.csv".format(index))):
        os.remove(file) #delete all previous data

def download_data(directory : str, index : int, minYear : int, maxYear : int, is_dir_create_if_not_exists : bool = False): 
    if minYear > maxYear:
        raise ValueError("Year range is incorrect")
    
    if index > 27 or index < 1:
        raise ValueError("Index is incorrect")
    
    if not os.path.exists(directory):
        if not is_dir_create_if_not_exists:
            raise ValueError("Direcory does not exist")
        else:
            os.makedirs(directory)

    #download raw data
    with requests.Session() as sess:
        base_url = "https://www.star.nesdis.noaa.gov/smcd/emb/vci/VH/get_provinceData.php?country=UKR&provinceID={}&year1={}&year2={}&type=Mean"
        url = base_url.format(NOAAIndex[index], minYear, maxYear)
        response = sess.get(url)

    path = os.path.join(directory, "province-{}.{}.csv".format(index, datetime.now().strftime("%d-%m-%Y_%H-%M")))        

    #preprocess and save to file line by line
    with open(path, 'w') as file:
        file.write("Year,Week,SMN,SMT,VCI,TCI,VHI\n")        
        for line in response.iter_lines(chunk_size=512, decode_unicode=True):
            temp = preprocess_raw_data(line)
            if temp:                                            
                file.write(temp) #write line by line

def download_if_not_exist(directory : str, minYear : int, maxYear : int):
    list_for_download = []
    for i in range(1,28):
        search_path = os.path.join(directory, f"province-{i}.*.csv")
        if len(glob(search_path)) == 0: #check 'is file with i province exists?'
            list_for_download.append(i)
    
    for i in list_for_download:
        download_data(directory, i, minYear, maxYear)

def download_all_data(directory : str, minYear : int, maxYear : int):
    for i in range(1,28):
        clear_dir(directory, i)
        download_data(directory, i, minYear, maxYear) 

def load_data_to_pd(directory : str, index : int):
    if not os.path.exists(directory):
        raise ValueError("Direcory does not exist")
    
    search_path = os.path.join(directory, f"province-{index}.*.csv")
    data_path = glob(search_path)[0]
    
    df = pd.read_csv(data_path, header=0, names=['Year','Week', 'SMN', 'SMT', 'VCI', 'TCI', 'VHI'])    
    df['Province'] = index 
    df['Province'] = df['Province'].astype('int32')
    
    #generate datetime field
    dt = df['Year'].astype('str') + "-" + df['Week'].astype('str') + "-1"
    df['Period'] = pd.to_datetime(dt, format='%Y-%W-%w')
    df.drop(['Year', 'Week'], axis=1, inplace=True)

    return df

def load_all_data_to_pd(directory : str):
    df = pd.DataFrame(columns=['SMN', 'SMT', 'VCI', 'TCI', 'VHI', 'Province', 'Period'])
    for i in range(1,28):
        df = df.append(load_data_to_pd(directory, i), ignore_index=True)
    
    return df   
