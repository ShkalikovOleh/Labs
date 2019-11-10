import requests
import datetime

def downloadData(index):
    url = "https://www.star.nesdis.noaa.gov/smcd/emb/vci/VH/get_provinceData.php?country=UKR&provinceID={}&year1=1991&year2=2019&type=Mean".format(index)
    response = requests.get(url)
    
    if response.status_code != 200:
        print("Error during response")
        return

    path = "data/vhi{}.{}.csv".format(index,datetime.datetime.now().strftime("%Y-%m-%d_%H-%M"))
    with open(path, 'w') as file:
        file.write("year,week,SMN,SMT,VCI,TCI,VHI\n")
        for line in response.text.splitlines():
            #data = str(line, 'utf-8')
            if line.__contains__('/'):
                continue            
            line = line.replace(' ', ',',2)
            file.write(line + '\n')


