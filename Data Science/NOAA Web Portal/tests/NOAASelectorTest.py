import sys
from io import StringIO
from datetime import datetime
from os.path import abspath as abspath


import unittest
import pandas as pd
import unittest.mock as mock

sys.path.append(abspath('./src'))
import noaa

class NOAASelectorTest(unittest.TestCase):

    def setUp(self):
        test_data = '''Period,SMN,SMT,VCI,TCI,VHI,Province
            07.01.1991, 0.085,264.19, 50.80, 39.07, 44.94, 2
            14.01.1991, 0.092,264.92, 62.61, 33.62, 48.11, 2
            21.01.1991, 0.095,265.62, 65.12, 31.94, 48.53, 2
            21.01.1991, 0.095,265.62, 65.12, 31.94, 48.53, 24
        '''
        test_data = test_data.replace(' ', '')
        test_data_io = StringIO(test_data)

        self.data = pd.read_csv(test_data_io)
        self.data['Period'] = pd.to_datetime(self.data['Period'], format='%d.%m.%Y')

        self.selector = noaa.NOAASelector(self.data)

    def test_province(self):
        actual = self.selector.by_province(2).select()
        self.assertEqual(len(actual), 3)
        
    def test_province_empty(self):
        actual = self.selector.by_province(6).select()
        self.assertEqual(len(actual), 0)

    def test_province_throw_if_incorrect(self):
        self.assertRaises(ValueError, self.selector.by_province, 28)
        self.assertRaises(ValueError, self.selector.by_province, 0)
        self.assertRaises(ValueError, self.selector.by_province, -4)

    def test_timerange(self):
        fromDate = datetime(1991,1,1)
        toDate = datetime(1991,1,15)
        actual = self.selector.by_timerange(fromDate, toDate).select()
        self.assertEqual(len(actual), 2)

    def test_timerange_empty(self):
        fromDate = datetime(1991,1,30)
        toDate = datetime(2020,1,15)
        actual = self.selector.by_timerange(fromDate, toDate).select()
        self.assertEqual(len(actual), 0)

    def test_timerange_throw_if_incorrect_range(self):                
        fromDate = datetime(2020,1,15)
        toDate = datetime(1991,1,30)
        self.assertRaises(ValueError, self.selector.by_timerange, fromDate, toDate)

    def test_all_and_checks(self):
        fromDate = datetime(1991,1,1)
        toDate = datetime(1991,1,15)
        actual = self.selector.by_province(2).And().by_timerange(fromDate, toDate).select()
        self.assertEqual(len(actual), 2)

    def test_all_or_checks(self):
        fromDate = datetime(1991,1,1)
        toDate = datetime(1991,1,15)
        actual = self.selector.by_province(24).Or().by_timerange(fromDate, toDate).select()
        self.assertEqual(len(actual), 3)


if __name__ == "__main__":
    unittest.main()
        