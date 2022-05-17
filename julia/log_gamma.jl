using DataStructures
using SpecialFunctions

setprecision(128)

bound = 1000000000

lb = log(bound)

queue = [3]

found = SortedSet([3])

paths = Dict([(3,3)])
sqrts = Dict([(3,0)])

while (length(queue)> 0)
    m = popfirst!(queue)
    x = loggamma(BigFloat(m)+BigFloat(1))

    i = 0
    p = ceil(log2(x/lb))
    q = max(p,0)

    i += q

    if (q==0)
        n = round(Int,exp(x/2^q))
    else
        n = floor(Int,exp(x/2^q))
    end

    # Check if n is a perfect square
    
    while (n>3)
        if !(n in found)
            push!(found,n)
            push!(queue,n)
            paths[n] = m
            sqrts[n] = i
        end
        n = isqrt(n)
        #n = isqrt(floor(n))
        #n = isqrt(BigInt(floor(n)))
        i += 1
    end
end

max_i = 3

while (max_i in found)
    global max_i += 1
end

v = 3
while (v<max_i)
    w = paths[v]
    println("$v,$(w),$(sqrts[v])")
    global v += 1
end
