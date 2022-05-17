import csv
import sys

R = RealField(1024)
one = R(1)

#bound = 10000000000000
#lb = log(bound)

file = open(sys.argv[1])
rows = csv.reader(file)

for row in rows:

    value = int(row[0])
    m = int(row[1])
    q = int(row[2])

    x = log_gamma(m+one)

    if q==0:
        n = round(exp(x))
    else:
        n = floor(exp(x/2^q))

    if not(value==n):
        print(value,m,q," -> ",n)

