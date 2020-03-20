import sys
from datetime import datetime
from os.path import abspath as abspath

import unittest
import unittest.mock as mock

sys.path.append(abspath('./src'))
import loader


class LoaderTest(unittest.TestCase):

    data_dir = "data"

    class MockResponse():
        def iter_lines(self, *args, **kwargs):
            yield "</HTML and unecessary data/>"
            yield "1991 01  0.046,265.27, 57.31,  9.66, 33.48"

    def test_download_preprocess(self):
        with mock.patch('loader.requests.Session.get') as req_mock:
            req_mock.return_value = self.MockResponse()

            with mock.patch('loader.open', mock.mock_open()) as file_mock:
                loader.download_data(self.data_dir, 4, 1991, 2019, True)

                expected = "1991,01, 0.046,265.27, 57.31,  9.66, 33.48\n"
                file_mock().write.assert_called_with(expected)
        pass

    @mock.patch('loader.requests.Session.get')
    def test_download_query(self, mock):        
        loader.download_data(self.data_dir, 4, 2001, 2019)
        expected = "https://www.star.nesdis.noaa.gov/smcd/emb/vci/VH/get_provinceData.php?country=UKR&provinceID=6&year1=2001&year2=2019&type=Mean"
        mock.assert_called_with(expected)

    def mock_glob_exists_file(self, arg): #22 does not exists
        if "22" in arg:
            return []
        else:
            return [""]    

    def test_download_if_not_exists(self):
        with mock.patch('loader.glob') as glob_mock:
            glob_mock.side_effect = self.mock_glob_exists_file

            with mock.patch('loader.download_data') as down_mock:
                year = datetime.now().year
                loader.download_if_not_exist(self.data_dir, 1991, year)

                down_mock.assert_called_with(self.data_dir, 22, 1991, year)
        

if __name__ == '__main__':
    unittest.main()