import re
import math

TOL = 1e-5

def matrix_mult(a, b):
    lines = len(a)
    result = []
    for i in range(lines):
        cols = len(a[i])
        result.append([])
        for j in range(cols):
            number = 0
            for k in range(lines):
                number += a[i][k] * b[k][j]
            result[i].append(number)
    return result

def lu(a, p, n):
    # p = [v for v in range(n)]
    for k in range(n - 1):
        pivot_val = math.fabs(a[p[k]][k])
        pivot_i = k
        for i in range(k+1, n):
            if pivot_val < math.fabs(a[p[i]][k]):
                pivot_val = math.fabs(a[p[i]][k])
                pivot_i = i
        tmp = p[k]
        p[k] = p[pivot_i]
        p[pivot_i] = tmp

        for i in range(k + 1, n):
            m = round(float(a[p[i]][k]) / a[p[k]][k], 3)
            for j in range(k, n):
                a[p[i]][j] = a[p[i]][j]-m*a[p[k]][j]
            a[p[i]][k] = m


def lu_solve(a, p, b, x, n):
    det = 0
    for i in range(n):
        det += a[p[i]][i]
    if math.fabs(det) < TOL :
        x = None
        return 

    y = [0 for v in range(n)]

    for i in range(n):
        y[i] = b[p[i]];
        for j in range(i):
            y[i] -= a[p[i]][j]*y[j]
    for i in range(n-1, -1, -1):
        x[i] = y[i]
        for j in range(i + 1, n):
            x[i] -= a[p[i]][j]*x[j]
        x[i] = round(float(x[i]) / a[p[i]][i], 3)

def lu_solve_trans(a, p, b, x, n):
    det = 0.0
    
    for i in range(n):
        det += a[p[i]][i]
    if math.fabs(det) < TOL:
        x = None
        return
    y = [0 for v in range(n)]
    for i in range(n):
        y[i] = b[i]
        for j in range(i):
            y[i] -= a[p[j]][i] * y[j]
        y[i] = round(float(y[i]) / a[p[i]][i], 3)

    for i in range(n-1, -1, -1):
        x[p[i]] = y[i]
        for j in range(i+ 1, n):
            x[p[i]] -= round(a[p[j]][i]*x[p[j]], 3)

    

def lu_print(a, p, n):
    l = [ [0.0 for j in range(n)] for i in range(n) ]
    u = [ [0.0 for j in range(n)] for i in range(n) ]
    for i in range(n):
        for j in range(i):
            l[i][j] = a[p[i]][j]
            u[i][i] = 0

        l[i][i] = 1
        u[i][i] = a[p[i]][i]

        for j in range(i+1,n):
            l[i][j] = 0
            u[i][j] = a[p[i]][j]
            
    print("L = %s" % l)
    print("U = %s" % u)