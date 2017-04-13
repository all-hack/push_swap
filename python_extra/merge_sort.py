
import random
from fractions import Fraction as ff
import sys
import pprint
prp = pprint.PrettyPrinter(indent=4, width=200)


op =0


def rt(stack):
    global op
    stack.append(stack.pop(0))    
    op += 1

def rrt(stack):
    global op
    stack.insert(0, stack.pop())
    op += 1

def trr(stack0, stack1):
    global op
    stack0.append(stack0.pop(0))
    stack1.append(stack1.pop(0))
    op += 1

def trrr(stack0, stack1):
    global op
    stack0.insert(0, stack0.pop())
    stack1.insert(0, stack1.pop())
    op += 1

def st(stack):
    global op
    stack.insert(1, stack.pop(0))
    op += 1

def pt(stack0, stack1):
    global op
    stack0.insert(0, stack1.pop(0))
    op += 1


def frt(stack):
    stack.append(stack.pop(0))

def frrt(stack):
    stack.insert(0, stack.pop())

def fpt(stack0, stack1):
    stack0.insert(0, stack1.pop(0))



def ra():
    global op
    a.append(a.pop(0))
    op += 1

def rb():
    global op
    b.append(b.pop(0))    
    op += 1

def rra():
    global op
    a.insert(0, a.pop())
    op += 1

def rrb():
    global op
    b.insert(0, b.pop())
    op += 1

def rr():
    global op
    a.append(a.pop(0))
    b.append(b.pop(0))
    op += 1

def rrr():
    global op
    a.insert(0, a.pop())
    b.insert(0, b.pop())
    op += 1

def sa():
    global op
    a.insert(1, a.pop(0))
    op += 1

def sb():
    global op
    b.insert(1, b.pop(0))
    op += 1

def ss():
    global op
    a.insert(1, a.pop(0))
    b.insert(1, b.pop(0))
    op += 1

def pa():
    global op
    a.insert(0, b.pop(0))
    op += 1

def pb():
    global op
    b.insert(0, a.pop(0))
    op += 1

def split_mid(mid, n):    
    for e in range(0, n):        
        if a[0] >= mid:
            pb()
        else:   
            ra()


def chunk(l, size):
    n = len(l) / size
    work = []

    for e in range(0, n):
        small = []
        for j in range(0, size):
            small.append(l[(e * size) + j])        
        work.append(small)

    i = len(work * size)
    rem = len(l) % size
    if rem > 0:
        work.append(l[i:i + rem])

    # print len(l) % size
    return work

def sort_2_asc(c, stack):
    for e in c:                
        if len(e) > 1:
            if e[0] < e[1]:
                rt(stack); rt(stack)
            else:
                st(stack); rt(stack); rt(stack)
    

    if len(c[len(c) - 1]) % 2 > 0:
        # rt(stack); rt(stack)  
        rt(stack)  

def sort_2_desc(c, stack):
    for e in c:                
        if len(e) > 1:
            if e[0] > e[1]:
                rt(stack); rt(stack)
            else:
                st(stack); rt(stack); rt(stack)
    
    if len(c[len(c) - 1]) % 2 > 0:
        # rt(stack); rt(stack)  
        rt(stack)

def naive_sort(c, stack0, stack1, size, desc):
    

    global check_pre_pb
    global smart_rrb
    global double_rotate
    global op

    if desc == 1:
        key_chng = -1
        print "\n\ndesc"
    else:
        key_chng = 1
        print "\n\nasc"

    new_c = []
    print "\n\nc: ", c
    print "new_c: ", new_c
    print "size: ", size
    analytics[str(size)] = []
    for e in c:
        n_op = op        
        print "\nstrt: ", e

        # if e == [2, 35]:
        #     pass   
        
        tmp = []
        abc = []
        
        p = sorted(e, key=lambda item: item * key_chng)

        if len(e) == size:
            num = len(e)
            split = len(e)/2

        else:            
            split = len(e)
            if len(new_c) > 0:
                e = e + new_c.pop(0)
            print e
            p = sorted(e, key=lambda item: item * key_chng)
            num = len(e)

        print "p: ", p        
        print "len(c): ", len(c)
        print "len(e): ", len(e)
        print "split: ", split
        print "size: ", size
        print "new_c: ", new_c
        smart_rrb_flag = 0
        rotate_count = 0
        if check_pre_pb == True:            
            for i in range(0, split):
                print "e: ", e
                print "p: ", p
                if e[0] == p[0]:
                    print "%d == %d"%(e[0], p[0])
                    rt(stack0)
                    abc.append(e.pop(0))
                    p.pop(0)
                else:
                    flag = 1
                    pt(stack1, stack0)
                    fpt(tmp, e)
        else:
            for i in range(0, split):
                pt(stack1, stack0)
                fpt(tmp, e)  
        
        # if len(tmp) > 2:
        #     print "\n\nsorted_finish"
        #     print "(e + list : ", e + list(reversed(tmp))
        #     print "sorted:     ", sorted(tmp + e, key=lambda item: item * key_chng)
        if e + list(reversed(tmp)) == sorted(tmp + e, key=lambda item: item * key_chng) and sorted_finish == 1 and len(tmp) > 2:
            print "\n\nsorted_finish"
            print "pre "
            print "e:   ", e
            print "tmp: ", tmp
            print "a: ", a
            print "b: ", 
            for y in range(0, len(e)):
                rt(stack0)
            for y in range(0, len(tmp)):
                pt(stack0, stack1)
            for y in range(0, len(tmp)):
                rt(stack0)
            print "post"
            print "e:   ", e
            print "tmp: ", tmp
            print "a: ", a
            print "b: ", 
            continue 
        for i in range(0, num):
            tmp_i = 0 if len(tmp) == 0 else len(tmp) - 1
            
            # print "abc: ", abc
            # print "tmp_i: ", tmp_i

            # print "e", len(e)
            # if len(e) != 0:
            # print ""
            if len(tmp) == 0:        
                print "tmp == 0: ", key_chng            
                for y in range(0, len(e)):
                    rt(stack0)
                    abc.append(e.pop(0))
                break

            elif len(e) == 0:
                print "\ne == 0: ", key_chng
                if smart_rrb_flag == 1:                    
                    for y in range(0, len(tmp) - 1):
                        rrt(stack1)
                print "a: ", a
                print "b: ", b
                for y in range(0, len(tmp)):
                    pt(stack0, stack1)
                    fpt(e, tmp)                    
                for y in range(0, len(e)):
                    rt(stack0)
                    abc.append(e.pop(0))
                break

            elif e[0] * key_chng < tmp[tmp_i] * key_chng:
                print "\ne < tmp: ", key_chng                
                print "e:   ", e
                print "tmp: ", tmp                
                print "a: ", a
                print "b: ", b
                if double_rotate == 1 and rotate_count < len(tmp) - 1 and len(tmp) > 2 and smart_rrb_flag == 0:
                        trr(stack0, stack1)
                        abc.append(e.pop(0))
                        print "double_rotate"
                        print "e:   ", e
                        print "tmp: ", tmp                        
                        print "a: ", a
                        print "b: ", b
                        print "len(tmp) -1: ", len(tmp)-2
                        print "rotate_count: ", rotate_count
                        rotate_count += 1
                
                else:
                    print "normal behavior"
                    rt(stack0)
                    abc.append(e.pop(0))

            else:                
                print "\n\n\ntmp < e: ", key_chng
                print "a: ", a
                print "b: ", b
                print "tmp: ", tmp
                print "e: ", e
                
                pp = sorted(tmp + e, key=lambda item: item * key_chng)
                # print "pp: ", pp
                # print "reversed(tmp) + e: ", list(reversed(tmp)) + e

                if len(tmp) == 2:
                    print "len(tmp) == 2"
                    if smart_rrb_flag == 1:
                        rrt(stack1)
                    st(stack1)
                    pt(stack0, stack1)
                    rt(stack0)                        
                    abc.append(tmp.pop(1))
                elif len(tmp) == 1:
                    print "len(tmp) == 1"
                    pt(stack0, stack1)
                    rt(stack0)
                    abc.append(tmp.pop(0))
                
                # elif list(reversed(tmp)) + e == pp and smart_rrb_flag == 0 and sorted_finish == 1:
                #     print "\n\nsorted_finish"
                #     for y in range(0, len(tmp)):
                #         pt(stack0, stack1)
                #         fpt(e, tmp)
                #     for y in range(0, len(tmp) + len(e)):
                #         rt(stack0)
                #         abc.append(e.pop(0))                    
                #     print "a: ", a
                #     print "b: ", b
                #     print "tmp: ", tmp
                #     print "e: ", e
                #     print "abc: ", abc

                #     break

                else:
                    if smart_rrb == True:
                        if smart_rrb_flag == 0:
                            smart_rrb_flag = 1
                            print "\nmin_i opt"

                            min_i = tmp.index(min(tmp, key=lambda item: item * key_chng)) - rotate_count
                            print "tmp: ", tmp
                            print "a: ", a
                            print "b: ", b
                            print "min_i: ", min_i
                            print "len(tmp): ", len(tmp)
                            print "len(tmp) - 1: ", len(tmp)-1
                            for y in range(0, min_i):
                                rt(stack1)

                        pt(stack0, stack1)
                        rrt(stack1)
                        rt(stack0)
                        abc.append(tmp.pop(len(tmp)-1))
                        print "tmp: ", tmp
                        print "a: ", a
                        print "b: ", b
                        # if len(tmp) == 3:
                            # sys.exit("fuckc")
                        # if len(tmp) == 3:                            
                        #     rrt(stack1); 
                    else:
                        for y in range(0, len(tmp) - 1):
                            rt(stack1)                        
                        pt(stack0, stack1)                                        
                        for y in range(0, len(tmp) - 1):                        
                            rrt(stack1)       
                        rt(stack0)                                 
                        abc.append(tmp.pop(len(tmp)-1))
        print "\nstarting new"
        print "a: ", a
        print "b: ", b 
        new_c.append(abc)
        analytics[str(size)].append((op - n_op))
    # print "n_op: ", n_op
    # print "n_op: ", op
    return new_c


def final_merge(c, d, stack0, stack1):    
    print "final_merge"
    print "c: ", c
    print "d: ", d
    for y in d[0]:
        pt(stack0, stack1)
    for y in c[0]:
        rrt(stack0)    
    
    
def find_runs(stack0):
    runs = []

    last = []    
    for e in stack0:   
        tmp = [e]
        if len(last) == 0:
            last = tmp
        elif abs(last[len(last)-1] - e) == 1:
            last.append(e)
        else:
            runs.append(last)
            last = tmp
    runs.append(tmp)
    return runs




def direction_roll(num, stack):
    # print "\n\ndirection_roll"
    index = stack.index(num)
    size = len(stack)
    if size - index < index:
        return 1
    else:
        return -1
    # print "stack index: ", index
    # print "size: ", size
    # print "index - size: ", index - size
    # print "size - index: ", size - index
    




def roll_num(num, stack0, stack1):    
    if direction_roll(num, stack0) < 0:
        while stack0[0] != num:
            rrt(stack0)        
    else:
        while stack0[0] != num:
            rt(stack0)

def roll_next(num, stack0, stack1):
    if direction_roll(num, stack0) < 0:
        while stack0[0] != num:
            rrt(stack0)
        rt(stack0)        
    else:
        while stack0[0] != num:
            rt(stack0)
        rt(stack0)

def roll_next_op(num, stack0, stack1, desc):
    
    if desc == 1:
        key_chng = -1
        print "desc"
    else:
        key_chng = 1
        print "asc"

    i = 0
    next = num + key_chng + key_chng
    print "next: ", next
    print "num: ", num
    # if stack0[0] == next:
    #     pt(stack1, stack0)
    #     i += 1
    #     next += key_chng

    print "dir: ", direction_roll(num, stack0)

    if direction_roll(num, stack0) < 0:
        # print "stack0[0]: ", stack0[0]
        while stack0[0] != num:
            if stack0[0] == next:
                pt(stack1, stack0)
                i += 1
                next += key_chng
            rrt(stack0)            
        rt(stack0)        
    else:
        # print "stack0[0]: ", stack0[0]        
        while stack0[0] != num:
            if stack0[0] == next:
                pt(stack1, stack0)
                i += 1
                next += key_chng
            rt(stack0)            
        rt(stack0)
        
    return i
        





def weird_sort(stack0, stack1, desc):
    print "\n\nweird_sort"
    if desc == 1:
        key_chng = -1
        start = max(stack0)
        fin = min(stack0)
        print "desc"
    else:
        key_chng = 1
        start = 0
        fin = max(stack0)
        print "asc"

    print "key_chng: ", key_chng
    print "start: ", start

    num = start + key_chng
    p = sorted(stack0, key=lambda item: item * key_chng)

    while stack0 != p:
        print "\na: ", a
        print "b: ", b

        roll_num(num, stack0, stack1)
        pt(stack1, stack0)
        print "a: ", a
        print "b: ", b
        
        # roll_next(num - key_chng, stack0, stack1)
        # pt(stack0, stack1)
        
        for e in range(0, roll_next_op(num - key_chng, stack0, stack1, desc) + 1):
            pt(stack0, stack1)
            if e > 0: 
                num += key_chng

        print "a: ", a
        print "b: ", b
        if num == fin:
            roll_num(start, stack0, stack1)
        num += key_chng
        

    print "finish: "
    print "a: ", a
    print "b: ", b
    pass

def weird_merge(stack0, stack1):

    
    size = len(stack1)

    while len(stack1) != 0:
        pt(stack0, stack1)
    for e in range(0, size):
        rrt(stack0)






















# n = 12
# a = random.sample(range(1000), n)
# # a = [91, 29, 53, 28, 14, 13, 2, 35, 83, 99, 72, 65]
# # a = [91, 29, 53, 28, 14, 13, 2, 35, 83, 72, 99, 65, 27]
# b = []
# s = sorted(a)

# mid = s[int(round(n/2.0))]

# print ''
# print "list:   ", a
# print "sorted: ", s
# print "size of array: ", n
# print "mid element:   ", mid

# print ''
# print "split and chunk to 2"
# split_mid(mid, n)
# c = chunk(a, 2)
# d = chunk(b, 2)
# print "a: ", a
# print "b: ", b
# print "c: ", c
# print "d: ", d
# print ''

# print "sort 2s"
# c = naive_sort_asc(c, a, b, 2)
# d = naive_sort_desc(d, b, a, 2)
# print "a: ", a
# print "b: ", b
# print ''

# print "chunk to 4"
# c = chunk(a, 4)
# d = chunk(b, 4)
# print "a: ", a
# print "b: ", b
# print "c: ", c
# print "d: ", d
# print ''

# print "sort to 4"
# c = naive_sort_asc(c, a, b, 4)
# d = naive_sort_desc(d, b, a, 4)
# print "a: ", a
# print "b: ", b
# print "c: ", c
# print "d: ", d
# print ''



## 12 list_sorts 10
# op 67 expected change -10 or 20
# a = [91, 29, 53, 28, 14, 13, 2, 35, 83, 99, 72, 65]

# 13
# a = [91, 29, 53, 28, 14, 13, 2, 35, 83, 72, 99, 65, 27]

#16
# a = [11, 76, 93, 98, 2, 30, 84, 24, 42, 44, 86, 43, 3, 5, 92, 10]
# 104 op 6n + 1/2n
# a = [6, 11, 7, 15, 16, 14, 13, 1, 9, 8, 3, 5, 4, 10, 12, 2]
# 109 op 6n + 13/16n
# a = [8, 6, 11, 14, 5, 7, 10, 13, 3, 4, 15, 1, 0, 2, 9, 12]

# 19
# a = [111, 9, 960, 181, 815, 658, 715, 461, 441, 931, 865, 130, 743, 907, 443, 828, 116, 446, 803]

# 20
# a = [229, 501, 356, 62, 494, 86, 410, 300, 567, 119, 615, 671, 976, 817, 605, 979, 985, 813, 794, 908]
# a = [14, 46, 218, 228, 276, 328, 345, 382, 393, 434, 472, 485, 587, 661, 694, 766, 885, 889, 914, 944]
# a = [451, 226, 534, 869, 84, 341, 778, 503, 415, 186, 537, 287, 677, 548, 803, 558, 335, 991, 193, 203]
# a = [18, 720, 606, 356, 96, 907, 996, 625, 56, 517, 926, 74, 679, 430, 617, 184, 899, 839, 891, 674]
# a = [229, 9849, 6354, 3914, 2246, 6945, 5547, 6855, 5802, 3073, 7292, 2580, 9503, 1404, 1579, 3710, 3745, 7446, 1653, 7900]
# a = [3452, 9778, 1023, 9659, 569, 2513, 4212, 2240, 915, 7224, 926, 8872, 8055, 1608, 5352, 2530, 1794, 6806, 3279, 8763]
# 152 op
# a = [437, 8567, 9443, 9184, 1355, 8702, 9913, 2725, 4004, 365, 4172, 3671, 5000, 7398, 8362, 1942, 1912, 3822, 8376, 2532]
# 166 op 8 n + 3/10n
# a = [5, 2, 13, 15, 3, 7, 18, 6, 19, 4, 10, 14, 0, 20, 16, 8, 9, 1, 11, 12]


# 40
# a = [771, 735, 572, 146, 206, 487, 997, 627, 241, 210, 826, 831, 946, 491, 922, 310, 212, 990, 232, 762, 292, 166, 567, 361, 359, 848, 628, 504, 185, 335, 563, 670, 688, 861, 265, 678, 235, 693, 211, 184]
# break
# a = [52, 504, 320, 430, 689, 438, 333, 620, 987, 632, 563, 270, 666, 0, 650, 274, 760, 963, 19, 217, 407, 397, 378, 739, 384, 834, 887, 170, 928, 379, 726, 710, 172, 119, 688, 755, 356, 686, 241, 369]
# a =  [421, 589, 1227, 5759, 1131, 2992, 7534, 6130, 2204, 6194, 3633, 7789, 7676, 1816, 1103, 8293, 2247, 8629, 3770, 1153, 9490, 280, 9009, 6159, 592, 8520, 1996, 9524, 2296, 4108, 6913, 8652, 5621, 6785, 9821, 3439, 2831, 5054, 3276, 2982]

## 100 list_sorts 102
# op 1415 expected change -100 or -200
# a = [685, 947, 280, 597, 528, 127, 28, 37, 111, 288, 25, 398, 849, 356, 577, 362, 573, 238, 920, 931, 775, 777, 555, 308, 959, 866, 940, 142, 756, 333, 64, 100, 904, 908, 571, 512, 781, 774, 826, 18, 927, 704, 518, 523, 843, 600, 980, 538, 445, 163, 567, 421, 877, 106, 510, 590, 563, 601, 353, 806, 545, 673, 278, 816, 498, 693, 454, 252, 773, 957, 57, 249, 971, 144, 486, 948, 490, 945, 318, 731, 811, 77, 164, 507, 262, 792, 307, 917, 711, 823, 295, 875, 926, 489, 44, 611, 314, 659, 427, 384]
# best op 1430, worst: 2820, smart_rrb: 2820-1592(-1228), check_pre_pb: 1592-1442(-150), double_rotate: 1396, sorted_finish: 1442-1430(-12)
# a = [855, 579, 497, 642, 350, 668, 148, 676, 11, 307, 416, 145, 34, 870, 653, 908, 837, 991, 473, 552, 759, 90, 968, 21, 60, 465, 64, 175, 874, 12, 838, 705, 489, 921, 539, 184, 464, 183, 330, 171, 766, 74, 271, 418, 43, 248, 268, 681, 213, 810, 872, 355, 432, 701, 17, 383, 836, 819, 386, 813, 289, 806, 671, 724, 385, 493, 182, 112, 255, 265, 200, 612, 427, 103, 441, 887, 282, 53, 250, 591, 292, 957, 462, 412, 522, 805, 210, 390, 707, 764, 648, 958, 608, 199, 414, 401, 994, 454, 177, 929]
# 1388 op 13n + 22/25n
# a = [29, 63, 28, 89, 24, 4, 99, 40, 30, 77, 16, 91, 19, 34, 94, 68, 48, 90, 20, 54, 73, 10, 35, 80, 41, 26, 60, 11, 18, 2, 45, 42, 74, 53, 50, 23, 39, 12, 43, 3, 38, 22, 47, 58, 72, 25, 81, 57, 88, 17, 37, 27, 64, 86, 75, 78, 76, 8, 14, 33, 31, 84, 7, 52, 93, 95, 1, 85, 36, 5, 71, 69, 98, 6, 87, 62, 65, 13, 32, 82, 59, 55, 67, 56, 21, 66, 46, 15, 79, 51, 92, 97, 70, 96, 49, 9, 83, 44, 61, 0]

# 500
# best op 10529, worst: 65711, smart_rrb: 65711-11319(-54392), check_pre_pb: 11319-10553(-766), sorted_finish: 10553-10529(-24)
# a = [731, 527, 216, 231, 75, 327, 638, 388, 567, 268, 986, 853, 851, 393, 666, 613, 956, 889, 708, 494, 923, 817, 915, 714, 221, 349, 448, 673, 668, 185, 305, 559, 650, 396, 826, 840, 617, 140, 394, 517, 310, 691, 405, 989, 304, 116, 228, 450, 438, 688, 841, 382, 972, 303, 451, 820, 934, 203, 728, 212, 964, 201, 440, 242, 262, 724, 146, 877, 992, 298, 744, 536, 678, 28, 474, 957, 281, 542, 540, 172, 730, 287, 469, 659, 890, 104, 119, 325, 982, 592, 968, 409, 634, 881, 62, 694, 752, 486, 187, 376, 143, 981, 359, 726, 908, 188, 364, 902, 99, 642, 777, 507, 155, 452, 476, 514, 152, 753, 321, 50, 329, 535, 114, 835, 518, 130, 702, 633, 522, 158, 277, 495, 415, 742, 245, 97, 411, 358, 3, 599, 808, 453, 274, 818, 395, 790, 44, 266, 523, 995, 17, 920, 822, 836, 427, 319, 180, 598, 655, 263, 347, 235, 556, 265, 308, 685, 340, 113, 627, 250, 532, 800, 632, 953, 587, 546, 294, 942, 355, 237, 76, 88, 397, 624, 93, 124, 880, 206, 444, 585, 511, 208, 631, 318, 901, 58, 849, 120, 630, 811, 719, 362, 462, 186, 761, 350, 105, 161, 785, 83, 129, 824, 295, 657, 870, 525, 249, 741, 506, 533, 225, 315, 163, 482, 812, 67, 19, 927, 352, 258, 156, 554, 784, 921, 344, 108, 49, 142, 53, 162, 398, 690, 966, 255, 101, 110, 707, 607, 139, 566, 736, 1, 846, 204, 472, 565, 264, 246, 770, 945, 983, 441, 959, 131, 169, 718, 636, 626, 656, 31, 184, 33, 788, 772, 301, 706, 439, 722, 117, 333, 621, 154, 858, 339, 797, 725, 900, 591, 512, 937, 939, 32, 695, 513, 470, 222, 484, 865, 832, 984, 334, 946, 178, 63, 179, 941, 903, 531, 699, 771, 605, 11, 390, 326, 384, 270, 545, 392, 342, 645, 769, 442, 936, 229, 654, 389, 681, 692, 115, 103, 209, 420, 869, 137, 758, 177, 647, 729, 710, 320, 508, 564, 230, 550, 94, 491, 367, 779, 682, 883, 283, 463, 118, 660, 748, 765, 144, 401, 299, 36, 670, 15, 855, 716, 931, 919, 847, 379, 477, 181, 153, 160, 595, 52, 418, 426, 850, 378, 743, 434, 432, 575, 286, 403, 102, 133, 833, 505, 547, 136, 663, 87, 980, 791, 783, 322, 260, 572, 999, 686, 417, 138, 218, 529, 580, 387, 259, 300, 971, 289, 430, 671, 804, 106, 9, 973, 930, 926, 879, 499, 868, 569, 806, 987, 429, 767, 419, 84, 109, 288, 537, 314, 338, 735, 39, 747, 867, 404, 56, 437, 402, 323, 555, 551, 309, 988, 198, 875, 485, 190, 948, 433, 738, 345, 679, 746, 369, 929, 904, 293, 302, 65, 781, 563, 145, 490, 576, 341, 175, 475, 481, 194, 365, 704, 337, 95, 202, 616, 243, 648, 285, 479, 501, 732, 81, 70, 794, 733, 112, 872, 147, 313, 422, 468, 871, 168, 574, 935, 754, 330]
# 10192 op 20n + 48/125n
# a = [486, 204, 34, 388, 38, 472, 164, 402, 272, 275, 434, 492, 96, 188, 175, 153, 215, 157, 237, 433, 468, 332, 474, 108, 3, 291, 238, 186, 65, 350, 339, 235, 103, 342, 456, 59, 483, 246, 244, 119, 304, 54, 16, 425, 174, 106, 477, 358, 78, 165, 9, 203, 336, 211, 394, 380, 335, 373, 4, 18, 32, 452, 428, 280, 233, 166, 25, 437, 220, 107, 135, 40, 368, 145, 143, 227, 0, 283, 397, 137, 234, 122, 163, 146, 348, 427, 30, 401, 307, 423, 15, 101, 384, 23, 190, 377, 286, 493, 14, 189, 140, 374, 347, 183, 29, 160, 436, 406, 248, 125, 305, 115, 412, 82, 310, 317, 285, 355, 111, 21, 236, 100, 408, 269, 424, 31, 219, 460, 77, 410, 498, 455, 61, 254, 364, 43, 370, 387, 301, 242, 60, 431, 5, 326, 70, 270, 71, 314, 224, 420, 369, 328, 112, 206, 192, 362, 405, 453, 92, 64, 149, 147, 81, 19, 207, 300, 294, 120, 133, 318, 282, 41, 485, 75, 277, 481, 274, 414, 7, 407, 159, 357, 36, 131, 168, 68, 365, 446, 473, 89, 196, 247, 259, 390, 138, 441, 8, 497, 375, 2, 379, 470, 57, 44, 191, 478, 260, 256, 319, 417, 262, 312, 162, 124, 24, 482, 287, 399, 199, 439, 293, 464, 449, 480, 360, 389, 338, 86, 185, 170, 366, 471, 201, 372, 261, 354, 187, 109, 398, 154, 496, 155, 263, 454, 48, 356, 308, 97, 156, 217, 346, 290, 432, 239, 253, 225, 47, 265, 281, 391, 53, 84, 341, 313, 443, 367, 479, 393, 302, 94, 144, 200, 476, 345, 371, 73, 381, 142, 419, 223, 99, 161, 74, 255, 429, 67, 458, 459, 444, 337, 91, 212, 51, 359, 28, 116, 426, 121, 306, 457, 484, 181, 325, 257, 385, 104, 55, 289, 333, 171, 180, 22, 141, 303, 251, 27, 451, 382, 69, 296, 327, 442, 130, 49, 76, 316, 158, 216, 102, 177, 148, 179, 386, 95, 210, 126, 279, 88, 278, 229, 226, 264, 232, 445, 90, 26, 418, 132, 110, 221, 105, 118, 413, 85, 6, 322, 152, 46, 268, 194, 494, 114, 411, 42, 299, 228, 129, 205, 403, 330, 392, 361, 288, 1, 329, 241, 127, 273, 209, 63, 351, 52, 117, 298, 252, 324, 245, 353, 340, 173, 62, 17, 309, 430, 343, 35, 45, 422, 469, 490, 475, 80, 499, 240, 202, 150, 409, 396, 66, 139, 292, 462, 184, 72, 98, 323, 151, 438, 193, 178, 113, 383, 284, 271, 487, 83, 222, 466, 87, 334, 37, 13, 491, 315, 93, 376, 195, 218, 395, 176, 465, 249, 321, 276, 20, 488, 467, 231, 267, 297, 58, 50, 11, 172, 440, 182, 79, 404, 400, 123, 489, 12, 243, 363, 10, 230, 435, 349, 447, 495, 213, 352, 415, 461, 266, 198, 136, 258, 448, 134, 197, 416, 250, 463, 344, 378, 39, 331, 311, 167, 128, 295, 56, 208, 33, 214, 450, 320, 169, 421]



n = len(a)
# n = 100; a = random.sample(range(10000), n)
b = []
past = list(a)
s = sorted(a)
mid = s[int(round(n/2.0))]
mid_i = s.index(mid)
split_mid(mid, n)

check_pre_pb = 1
smart_rrb = 1
double_rotate = 1
sorted_finish = 1
kill = 0

sss = s[mid_i:]
sss.reverse()

# print "\na:        ", a
# print "sorted a: ", sorted(a)
# print "s:        ", s[:mid_i]
# print "b:        ", b
# print 'sorted b: ', sorted(b)
# print "sss:      ", s[mid_i:]






sub_len = 2
i = 0
num_list_sorted = 0

analytics = {}




print "a: ", a
print "b: ", b

weird_sort(a, b, 0)
weird_sort(b, a, 1)
weird_merge(a, b)

# print "runs a: ", find_runs(a)
# print "runs b: ", find_runs(b)


# while a != s[:mid_i] and b != sss:
#     print "\n\nsub_len: ", sub_len
#     c = chunk(a, sub_len)
#     d = chunk(b, sub_len)    
    
#     xx = list(a)
#     c = naive_sort(c, a, b, sub_len, 0)
    
#     yy = list(b)    
#     d = naive_sort(d, b, a, sub_len, 1)

#     print "\n\nstats:"
#     print "sub_le: ", sub_len
#     print "len(a): ", len(a)
#     print "    xx: ", xx
#     print "     a: ", a    
#     print "sorted: ", s[:mid_i]
#     print "len(c): ", len(c)
#     print "     c: ", c
#     print "len(b): ", len(b)
#     print "    yy: ", yy
#     print "     b: ", b    
#     print "sorted: ", sss
#     print "len(d): ", len(d)
#     print "     d: ", d
#     print ""
#     print ""
#     print "past: ", past
#     print ""
#     print "s: ", s
    
#     if kill > 0:
#         if i == kill:
#             sys.exit("\n\nkilled by kill")

#     num_list_sorted += len(a) / sub_len + len(b) / sub_len
#     num_list_sorted += 1 if len(a) % sub_len != 0 else 0
#     num_list_sorted += 1 if len(b) % sub_len != 0 else 0
#     i += 1
#     sub_len = sub_len * 2

# # if a == s[:mid_i] and b == sss:
# #     a = s
# #     b = []

# if len(b) > 0:
#     final_merge(c, d, a, b)

print ""
print ""
print "results"
print "a: ", a
if a == sorted(a):
    valid = True
else:
    valid = False
# print "check_pre_pb: ", check_pre_pb
# print "smart_rrb: ", smart_rrb
# print "sorted_finish: ", sorted_finish
print "sorted: ", valid
print ''
print 'mid: ', mid
# print "s: ", s[:mid_i]
# print 'sss: ', sss
print ''
print "n: ", n
print "op: ", op
# print "big(O): %dn + %d/%dn" % (op / n, op % n, n)
frac = ff(op % n, n)
print "big(O): %dn + %d/%dn" % (op / n, frac.numerator, frac.denominator)
# print "sub_len: ", sub_len / 2
# print "number of iterations: ", i
# print "num_list_sorted: ", num_list_sorted

print "analytics: "
prp.pprint(analytics)

# k = [11, 2, 30, 24, 42, 3, 5, 10]
# k = [42, 24, 30, 11, 76, 93, 98, 84, 44, 86, 43, 92]
# k = [76, 93, 98, 84, 86, 92]
# k = [93, 98, 92]
# k = [92, 93, 86, 84, 76, 43, 44, 11, 30, 24, 42, 2, 3, 5, 10]

# print "k: ", sorted(k)[int(round(len(k)/2.0))]

# sss = s[mid_i:]
# sss.reverse()
print ""
# print ff(op % n, n)



















