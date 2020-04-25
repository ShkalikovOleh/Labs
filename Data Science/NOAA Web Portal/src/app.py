import os
import sys
from glob import glob
from datetime import datetime

import seaborn as sns
from spyre import server

import loader
import noaa


class NOAAWebPortal(server.App):
    title = "NOAA Web Portal"

    inputs = [
        {
            "type": 'dropdown',
            "label": 'Series',
            "options": [
                {"label": "VHI", "value": "VHI"},
                {"label": "TCI", "value": "TCI"},
                {"label": "VCI", "value": "VCI"}],
            "value": 'VHI',
            "key": 'series_type',
            "action_id": "update_data"
        },
        {
            "type": 'dropdown',
            "label": 'Province',
            "options": [
                {"label": "Вінницька", "value": 1},
                {"label": "Волинська", "value": 2},
                {"label": "Дніпропетровська", "value": 3},
                {"label": "Донецька", "value": 4},
                {"label": "Житомирська", "value": 5},
                {"label": "Закарпатська", "value": 6},
                {"label": "Запорізька", "value": 7},
                {"label": "Івано-Франківська", "value": 8},
                {"label": "Київська", "value": 9},
                {"label": "Кіровоградська", "value": 10},
                {"label": "Луганська", "value": 11},
                {"label": "Львівська", "value": 12},
                {"label": "Миколаївська", "value": 13},
                {"label": "Одеська", "value": 14},
                {"label": "Полтавська", "value": 15},
                {"label": "Рівенська", "value": 16},
                {"label": "Сумська", "value": 17},
                {"label": "Тернопільська", "value": 18},
                {"label": "Харківська", "value": 19},
                {"label": "Херсонська", "value": 20},
                {"label": "Хмельницька", "value": 21},
                {"label": "Черкаська", "value": 22},
                {"label": "Чернівецька", "value": 23},
                {"label": "Чернігівська", "value": 24},
                {"label": "АР Крим", "value": 25},                
                {"label": "Київ", "value": 26},
                {"label": "Севастополь", "value": 27}],
            "value": 26,
            "key": 'province_index',
            "action_id": "update_data"
        },
        {
            "type": 'text',            
            "label": 'From',
            "value": '24.08.1991',
            "key": 'time_range_min',
            "action_id": "update_data"
        },
        {
            "type": 'text',            
            "label": 'To',
            "value": datetime.now().strftime('%d.%m.%Y'),
            "key": 'time_range_max',
            "action_id": "update_data"
        }]

    controls = [
        {
            "type": "button",
            "id": "update_data",
            "label": "Show data"
        }]

    tabs = ["Plot", "Table"]

    outputs = [
        {
            "type": "plot",
            "id": "plot",
            "control_id": "update_data",
            "tab": "Plot",
            "on_page_load": True
        },
        {
            "type": "table",
            "id": "table_id",
            "control_id": "update_data",
            "tab": "Table"
        }]    

    def __init__(self, df):
        self.selector = noaa.NOAASelector(df)

    def paramatrize_selector(self, params):
        self.selector.reset()
        province = int(params['province_index'])
        
        try:
            fromDate = datetime.strptime(params['time_range_min'], '%d.%m.%Y')
        except:
            fromDate = datetime(1991,8,24)

        try:
            toDate = datetime.strptime(params['time_range_max'], '%d.%m.%Y')
        except:            
            toDate = datetime.now()

        if fromDate > toDate:
            fromDate = datetime(1991,8,24)
            toDate = datetime.now()

        self.selector.by_province(province).by_timerange(fromDate, toDate)

    def getPlot(self, params):
        data = self.getData(params)
        return sns.lineplot(x='Period', y=params['series_type'], data=data).get_figure()

    def getData(self, params):                        
        self.paramatrize_selector(params)
        return self.selector.select(column=params['series_type'])


if __name__ == "__main__":
    if len(sys.argv) > 1:
        data_dir = sys.argv[1]
    else:
        raise ValueError("Data directory must be specify as first argument")
    
    loader.download_if_not_exist(data_dir, 1991, datetime.now().year)    
    df = loader.load_all_data_to_pd(data_dir)    
    
    portal = NOAAWebPortal(df)
    portal.launch()
