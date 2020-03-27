from timeit import timeit
import numpy as np


def get_mean_execution_time(expr_lambda, count):
    all_time = timeit(expr_lambda, number=count)
    return all_time / count


def get_mean_execution_time_iterative(array, func, count, step):    
    result = []

    for i in range(0, len(array), step):
        data = array[:i]
        result.append(get_mean_execution_time(lambda: func(data), count))

    if len(array) // step != 0:
        result.append(get_mean_execution_time(lambda: func(array), count))

    return np.array(result)