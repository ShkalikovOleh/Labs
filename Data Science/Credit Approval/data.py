import os
import requests


def download_credit_ds():
    if not os.path.exists("data"):
        os.makedirs("data")    

    url = "https://archive.ics.uci.edu/ml/machine-learning-databases/credit-screening/crx.data"
    response = requests.get(url)
    if response.status_code != 200:
        raise ValueError

    with open("data/credit-approval.csv", 'wb') as file:
        for chunk in response:
            file.write(chunk)