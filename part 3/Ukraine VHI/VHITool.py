import pandas as pd
import Utils as utils

def getVHISeriesByProvinceAndYear(df, provinceId, year):
    return df[(df.Province == provinceId) & (df.year == year)].VHI


def getVHISeriesByProvince(df, provinceId):
    return df[df.Province == provinceId].VHI


def getYearInVHIRangeByProvince(df, provinceId, min, max):
    return df[(df.Province == provinceId) & (df.VHI >= min) & (df.VHI <= max)].year.unique()


df = utils.uploadDataFromDirectory("data")

series = getVHISeriesByProvinceAndYear(df,1,2017)
print("Mean of 1 in 2017: {}".format(series.mean()))
print("Min of 1 in 2017: {}".format(series.min()))
print("Max of 1 in 2017: {}".format(series.max()))

print("Medium in 1: {}".format(getYearInVHIRangeByProvince(df,1,15,35)))
print("Critical in 1: {}".format(getYearInVHIRangeByProvince(df,1,0,15)))