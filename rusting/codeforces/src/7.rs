use std::io::prelude::*;
use std::fs::File;
use std::error::Error;
use std::path::Path;
fn main() -> (){
    let path = Path::new("7.input");
    let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", path.display(), why.description()),
        Ok(file) => file,
    };
    
    let mut s = String::new();
    file.read_to_string(&mut s);
    print!("{}", s);

}
