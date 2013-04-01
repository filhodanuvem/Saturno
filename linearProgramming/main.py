from lp.matrix.file import Reader
import lp.matrix.decomplu as dec



def main():
    reader = Reader('./data/in_3x3')
    n = reader.getOrder()[0]
    a = reader.getMatrix()
    b = reader.getB()
    p = [v for v in range(n)]
    clone_a = a[:]
    dec.lu(a,p,n)
    
    dec.lu_print(a, p, n)
    x = [0 for v in range(n)]
    dec.lu_solve(a, p, b, x, n)
    print("p = %s" % p)
    print("x = %s" % x)
    dec.lu_solve_trans(a,p,b,x,n)
    x = [round(v,3) for v in x]
    print("lambda = %s" % x)

if __name__ == '__main__':
    main()