import requests
import datetime
import glob
import os
import pandas as pd


def downloadData(index):
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
        25:4
    }
    prefix = "0" if index < 10 else ""


    url = "https://www.star.nesdis.noaa.gov/smcd/emb/vci/VH/get_provinceData.php?country=UKR&provinceID={}&year1=1991&year2=2019&type=Mean".format(NOAAIndex[index])
    response = requests.get(url)
    
    if response.status_code != 200:
        print("Error during response")
        return

    path = "data/vhi{}{}.{}.csv".format(prefix,index,datetime.datetime.now().strftime("%Y-%m-%d_%H-%M"))

    for file in glob.glob("data/vhi{}*.csv".format(index)):
        os.remove(file)

    with open(path, 'w') as file:
        file.write("year,week,SMN,SMT,VCI,TCI,VHI\n")
        for line in response.text.splitlines():            
            if line.__contains__('/'):
                continue            
            line = line.replace(' ', ',',2)
            file.write(line + '\n')


def downloadDataForAllProvince():
    for i in range(1,26):
        downloadData(i)


def uploadDataFromDirectory(path):
    all_files = glob.glob(path + "/*.csv")    
    dfs = []    

    for file in all_files:        
        df = pd.read_csv(file, index_col=None, header=0)
        df['Province'] = df.apply(lambda row: int(file[len(path) + 4] + file[len(path) + 5]), axis = 1)
        dfs.append(df)
    
    return pd.concat(dfs, ignore_index=True)