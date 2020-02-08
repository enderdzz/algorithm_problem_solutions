// https://rust.cc/article?id=76f2526f-3627-414c-8023-65b5b1fa77e6
use std::str::FromStr;
use std::num::ParseIntError;

#[derive(Debug, PartialEq)]
struct MyInt(i32);

impl FromStr for MyInt {
    type Err = ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let astr = &s[1..s.len()-1];
        match astr.parse::<i32>() {
            Ok(n) => Ok(MyInt(n)),
            Err(e) => Err(e),
        }
    }
}

fn main() -> () {
    
    let mut t = String::new(); 
    // if you want change the string later, you should be use String.
    // or you can use &str slice.
    let t_ = "loveyou"; // t_ is str type
    let mut tt = t_.to_string();

    // '+' operator will change the first var's owner, and second car should be the ref
    //format!(); not change param owner
    
    let mut s = String::from("hello");
    s.push('c');
    let deref_s : &str = s.as_str(); // not &mut str
    
    println!("hi {}", deref_s);

    // std::str
    // parse原型 pub fn parse<F>(&self) -> Result<F, <F as FromStr>::Err> where F: FromStr,
    // parse可以解析任何实现了FromStr trait的类型，出错则返回std::str::FromStr::Err，这是一个关联类型，在为目标类型实现FromStr的时候，确定具体类型。
    // FromStr
    /* 
    pub trait FromStr {
        type Err;
        fn from_str(s: &str) -> Result<Self, Self::Err>;
    } */
    let n = "7"; // not '7', that's a char.
    let n = n.parse::<i32>().unwrap();
    println!("{:?}", n); // i64, u32, u64
    let n = "7.5".parse::<f64>().unwrap();
    let n: f64 = "1.3423423534324679".parse::<f64>().unwrap();
    println!("{:?}", n);

    let astr = "<142>";
    let n: MyInt = astr.parse().unwrap();
    println!("{:?}", n);
}
/* FromStr std type list:
i8, i16, i32, i64, i128, isize
u8, u16, u32, u64, u128, usize
f32, f64
bool
char
String
IpAddr, Ipv4Addr, Ipv6Addr
SocketAddr, SocketAddrV4, SocketAddrV6
NonZeroI8, NonZeroI16, NonZeroI32, NonZeroI64, NonZeroI128, NonZeroIsize
NonZeroU8, NonZeroU16, NonZeroU32, NonZeroU64, NonZeroU128, NonZeroUsize
PathBuf
TokenStream
*/