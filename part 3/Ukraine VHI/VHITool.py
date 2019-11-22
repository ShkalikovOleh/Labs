import pandas as pd
import Utils as utils

def getVHISeriesByProvinceAndYear(df, provinceId, year):
    return df[(df.Province == provinceId) & (df.year == year)].VHI


def getVHISeriesByProvince(df, provinceId):
    return df[df.Province == provinceId].VHI


def getYearInVHIRangeByProvince(df, provinceId, min, max, procentByYear):
    years = df[(df.Province == provinceId)].year.unique()
    results = []
    for year in years:
        series = getVHISeriesByProvinceAndYear(df, provinceId, year)
        percent = series[(series >= min) & (series <= max)].count() * 100 / series.count()
        if(percent >= procentByYear):
            results.append(year)
    return results


df = utils.uploadDataFromDirectory("data")

count = df.isna().any().count()
for i in range(1991,2019):
    count += 52*25 - df[(df.year == i)].week.count()
print(count)

series = getVHISeriesByProvinceAndYear(df,1,2017)
print("Mean of 1 in 2017: {}".format(series.mean()))
print("Min of 1 in 2017: {}".format(series.min()))
print("Max of 1 in 2017: {}".format(series.max()))

print("Medium in 1: {}".format(getYearInVHIRangeByProvince(df,1,15,35,30)))
print("Critical in 1: {}".format(getYearInVHIRangeByProvince(df,1,0,15,30)))