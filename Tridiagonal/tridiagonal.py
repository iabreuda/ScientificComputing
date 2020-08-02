import numpy as np
from scipy import linalg
from scipy.sparse.linalg import spsolve
from scipy.sparse import csc_matrix
import time

diagP = np.random.rand(10000)
diagS = np.random.rand(9999)

b = np.random.rand(10000)

a = np.diag(diagP, k = 0) + np.diag(diagS, k = 1) + np.diag(diagS, k = -1)

#Denso
start_time = time.time()
result = linalg.solve(a, b, assume_a='gen')
print("Sistema denso geral: %s seconds ---" % (time.time() - start_time))

#Denso Simetrico
start_time = time.time()
result = linalg.solve(a, b, assume_a='sym')
print("Sistema denso simetrico: %s seconds ---" % (time.time() - start_time))

##Esparsa
start_time = time.time()
result = spsolve(a, b)
print("Sistema esparso: %s seconds" % (time.time() - start_time))

##Tridiagonal Simetrica
start_time = time.time()
Ab = np.zeros((3, 10000))
Ab[0,1:] = diagS
Ab[1,:] = diagP
Ab[2,:-1] = diagS
result = linalg.solve_banded((1,1), Ab, b)
print("Sistema Tridiagonal Simetrico: %s seconds" % (time.time() - start_time))
