




ind = 2
fn = 1
fnMin1 = 1

while True:
    tmp = fn
    fn = fn + fnMin1
    fnMin1 = tmp

    print(ind)
    ind += 1
    print(fn)
    if len(str(fn)) >= 1000:
        print(ind)
        break
