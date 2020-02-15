use std::io;
//use std::collections::BTreeMap;
use std::collections::HashMap;

fn bitcount(x: i32) -> i32 {
    let mut count = 0;
    let mut cur = x;
    while cur != 0 {
        cur -= cur & (-cur);
        count += 1;
    }
    count
}

fn work(a: Vec<i32>) -> i32 {
    let lowmask  = (1 << 15) - 1;
    let highmask = lowmask << 15;
    let lowbits  = (0..(1<<15)).map(|x:i32|->Vec<i32>{a.iter().map(|y:&i32|->i32{bitcount(x ^ ( y & lowmask))}).collect()});
    let highbits = (0..(1<<15)).map(|x:i32|->Vec<i32>{a.iter().map(|y:&i32|->i32{bitcount((x<<15) ^ (y & highmask))}).collect()});
    let mut hm = HashMap::new();
    
    let mut index = 0;
    for cur in lowbits {
        let first = cur[0];
        //println!("{:?}", cur);
        let result: Vec<i32> = cur.iter().map(|x:&i32|->i32 {*x - first}).collect();
        //println!("{:?} {}", result,index);
        hm.insert(result, index);
        index += 1;
    }
    index = 0;
    for cur in highbits {
        let first = cur[0];
        let result: Vec<i32> = cur.iter().map(|x:&i32|->i32{first - *x}).collect();
        //println!("{:?} {}", result,index);
        if let Some(x) = hm.get(&result) {
            return (index << 15) + x;
        }
        index += 1;
    }
    -1
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let _n: i32 = s.trim().parse().unwrap();
    s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let a: Vec<i32> = s.trim().split_whitespace().map(|x:&str| -> i32{x.trim().parse().unwrap()}).collect();
    println!("{}", work(a));
}