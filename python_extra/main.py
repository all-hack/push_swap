
import pprint
import operator


pp = pprint.PrettyPrinter(indent=2)


 
# 10
# n = [2, 20, 9, 14, 19, 7, 5, 6, 10, 17]

# 5
n = [10, 17, 19, 12, 3]

# 3
# n = [13, 2, 6]
# n = [2, 13, 6]


s = sorted(n)
lowest = s[0]
n_len = len(n)

kn = {}
ks = {}

board = []

add = 0

for i, e in enumerate(n):
    kn[e] = i

# kn = sorted(kn.items(), key=operator.itemgetter())
# print kn
for i, e in enumerate(s):
    ks[e] = i


diff_from_0_total = 0
diff_from_head_total = 0
max_diff = 0
min_diff = 0
average_dif = 0


ra_val = -1
rra_val = 1

ra_total = 0
rra_total = 0



def diff0(kn, ks):
    return ks[e] - kn[e] if abs(n_len - kn[e]) > kn[e] else -1 * (n_len - kn[e])

def ra(kn, ks):
    return (ks[e] - kn[e]) + ra_val if abs(n_len - kn[e] + ra_val) > kn[e] + ra_val else -1 * (n_len - kn[e]) + ra_val
    # return diff0(kn, ks) + ra_val

def rra(kn, ks):
    return (ks[e] - kn[e])+ rra_val if abs(n_len - kn[e])+ rra_val > kn[e] + rra_val else -1 * (n_len - kn[e]+ rra_val)
    # return diff0(kn, ks) + rra_val



for i, e in enumerate(kn):
    j = {
        "value": e,
        "unsorted": kn[e],
        "sorted": ks[e],
        "diff_from_0": diff0(kn, ks),
        "diff_from_head": abs(kn[e] - lowest + i),
        "ra": ra(kn, ks),
        "rra": rra(kn, ks)

    }
    board.append(j)

    if j["diff_from_0"] > abs(max_diff):
        max_diff = abs(j["diff_from_0"])
    if j["diff_from_0"] < abs(min_diff):
        max_diff = abs(j["diff_from_0"])
    diff_from_0_total += abs(ks[e] - kn[e])
    diff_from_head_total += abs(kn[e] - lowest + i)
    ra_total += ra(kn, ks)    
    rra_total += rra(kn, ks)


average_diff = diff_from_0_total / n_len


print "n: ", n
print "s: ", s

print "kn:   ", kn
print "ks:   ", ks

print pp.pprint(board)
print "n_len: ", n_len
print "diff_from_0_total: ", diff_from_0_total
print "diff_from_head_total: ", diff_from_head_total
print "max_diff: ", max_diff,
print "min_diff: ", min_diff
print "min_diff: ", average_diff
print "ra_total: ", ra_total
print "rra_total: ", rra_total



