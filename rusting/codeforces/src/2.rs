use std::io::{stdin, BufRead};

#[inline] // #[inline(always)] is not a good idea.
fn solve(x: u32, y: u32) -> bool {
    match x {
        0 => unreachable!(),
        1 => y == 1,
        2 | 3 => y < 4,
        _ => true
    }
}
fn main(){
    for line in stdin().lock().lines().skip(1).map(|x| x.unwrap()) {
        let (x, y) = {
            let mut iter = line.split_ascii_whitespace().map(|x| x.parse().unwrap());
            (iter.next().unwrap(), iter.next().unwrap())
        };

        if solve(x, y) {
            println!("YES");
        } else {
            println!("NO");
        }
    } 
}

/*
https://doc.rust-lang.org/std/macro.unreachable.html
If the determination that the code is unreachable proves incorrect, the program immediately terminates with a panic!.
fn foo(x: Option<i32>) {
    match x {
        Some(n) if n >= 0 => println!("Some(Non-negative)"),
        Some(n) if n <  0 => println!("Some(Negative)"),
        Some(_)           => unreachable!(), // compile error if commented out
        None              => println!("None")
    }
}
*/