#pragma once

#include "Matrix.h"

namespace LinAlg
{
    template<typename T>
    void gaussJordanEliminationStep(IMatrix<T> &matrix, size_t i, size_t j)
    {
        for (size_t k = 0; k < matrix.nrow(); k++)
        {
            auto pivot = matrix(i, j);
            auto mult = matrix(k, j) / pivot;
            for (size_t l = 0; l < matrix.ncol(); l++)
            {
                if (i == k)
                    matrix(k, l) = matrix(k, l) / pivot;
                else if (j == l)
                    matrix(k, l) = 0;
                else
                    matrix(k, l) = matrix(k, l) - mult * matrix(i, l);
            }
        }
    }

    template<typename T>
    void gaussEliminationStep(IMatrix<T> &matrix, size_t i, size_t j)
    {
    for (size_t k = i + 1; k < matrix.nrow(); k++)
        {
            auto mult = matrix(k, j) / matrix(i, j);
            for (size_t l = j; l < matrix.ncol(); l++)
            {
                if (j == l)
                    matrix(k, l) = 0;
                else
                    matrix(k, l) = matrix(k, l) - mult * matrix(i, l);
            }
        }
    }
}