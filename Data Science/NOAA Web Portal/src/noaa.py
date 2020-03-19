from datetime import datetime
from abc import ABC, abstractmethod

import numpy as np
import pandas as pd


class SelectionStategy(ABC):
    @abstractmethod
    def apply(self, main_condition, new_condition):
        pass
        

class AndStategy(SelectionStategy):
    def apply(self, main_condition, new_condition):
        return main_condition & new_condition


class OrStategy(SelectionStategy):
    def apply(self, main_condition, new_condition):
        return main_condition | new_condition


class NOAASelector():    
    def __init__(self,  df : pd.DataFrame):
        self.df = df
        self.selection_stategy = AndStategy()
        self.reset()

    def reset(self):
        self.condition = np.ones((len(self.df), ), dtype=bool)

    def And(self):
        self.selection_stategy = AndStategy()
        return self

    def Or(self):
        self.selection_stategy = OrStategy()
        return self

    #specify timerange
    def by_timerange(self, min : datetime, max : datetime):
        if min > max:
            raise ValueError('Time range is incorrect')
        
        time_condition = (self.df['Period'] >= min) & (self.df['Period'] <= max)
        self.condition = self.selection_stategy.apply(self.condition, time_condition)
        
        return self

    #specify province
    def by_province(self, province : int):
        if province > 27 or province < 1:
            raise ValueError("Province is incorrect")
        
        province_condition = (self.df['Province'] == province)
        self.condition = self.selection_stategy.apply(self.condition, province_condition)

        return self

    def select(self, column : str = None, is_reset : bool = False):
        result = self.df[self.condition]        
        if column:            
            result = result.filter(['Period',column])

        if is_reset:
            self.reset()

        return result