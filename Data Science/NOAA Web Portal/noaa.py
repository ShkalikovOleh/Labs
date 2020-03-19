from datetime import datetime

import numpy as np
import pandas as pd


class NOAASelector():
    def __init__(self,  df : pd.DataFrame):
        self.df = df
        self.reset()


    def reset(self):
        self.condition = np.ones((len(self.df), ), dtype=bool)


    def by_timerange(self, min : datetime, max : datetime):
        self.condition = self.condition & (self.df['Period'] >= min) & (self.df['Period'] <= max)
        return self


    def by_province(self, province : int):
        if province > 27 or province < 1:
            raise ValueError("Province is incorrect")
        
        self.condition = self.condition & (self.df['Province'] == province)
        return self


    def select(self, column : str = None, is_reset : bool = False):
        if column:
            temp = self.df[self.condition]
            temp = { "Period" : temp['Period'], column : temp[column]}
            result = pd.DataFrame(temp)
        else:
            result = self.df[self.condition]

        if is_reset:
            self.reset()

        return result