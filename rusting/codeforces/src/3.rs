extern crate core; // must add this line.

use std::iter::FromIterator;
use std::cmp::{min, max};
use core::fmt::Debug;
use core::str::FromStr;

fn read_line() -> String {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    buf.trim().to_string()
}

fn parse_line<T: FromStr>() -> T
where
    T::Err: Debug,
{
    let line = read_line();
    line.parse::<T>().unwrap()
}

fn split_parse_line<T:FromStr>() -> Vec<T>
where
    T::Err: Debug,
{
    let line = read_line();
    line
        .split(' ')
        .map(|x| x.parse::<T>().unwrap())
        .collect()
}

fn gcd(a: u32, b:u32) -> u32 {
    if b != 0 {
        gcd(b, a % b)
    } else {
        a
    }
}

fn min_dominated_len(arr: &[usize]) -> Option<usize> {
    let mut seen = vec![(None, None); arr.len()+1];
    let mut min_dist = vec![core::usize::MAX; arr.len()+1];
    if arr.len() < 2 {
        return None;
    }
    for (i, &el) in arr.iter().enumerate() {
        seen[el] = match seen[el] {
            (None, None) => (Some(i), None),
            _ => (Some(i), seen[el].0),
        };
        //println!("{:?}", seen[el]);
        if let (Some(last), Some(pre_last)) = seen[el] {
            min_dist[el] = min(last - pre_last, min_dist[el]);
        }
        //println!("Min last: {}", min_dist[el]);
    }
    min_dist.iter().filter(|&&x| (x > 0) && (x < core::usize::MAX)).min().map(|x| x + 1) //Because the closure passed to filter() takes a reference, and many iterators iterate over references, this leads to a possibly confusing situation, where the type of the closure is a double reference
}

fn process() {
    let _count = read_line();
    let arr = split_parse_line::<usize>(); // 严格限制空格个数
    match min_dominated_len(&arr) {
        Some(len) => println!("{}", len),
        None => println!("-1"),
    }
}

fn main() {
    let query_count = parse_line::<usize>();
    (0..query_count).for_each(|_| process());
}