use std::fs::File;
use std::io;
use std::io::prelude;
use std::io::BufRead;
use std::io::BufReader;
use std::str::FromStr;

// reads a multi-line text file into a Vector.
// from sts10/eyeoh/src/lib.rs#L33-L50
pub fn read_by_line <T: From Str>(file_path: &str) -> io::Result<Vec<T>> {
    let mut vec = Vec::new();
    let f = File::open(file_path.trim_matches(|c| c == '\'' || c == ' '))?;
    let file = BufReader::new(&f);
    for line in file.lines() {
        match line?.parse() {
            Ok(l) => vec.push(l),
            Err(_e) => {
                panic!("Error reading a line of the file");
            }
        }
    }
    Ok(vec)
// it reads a text file into a Vector of `char`s
pub fn read_string_from_file_to_vector(file_path: &str) -> io::Result<Vec<char>> {
    let mut f = File::open(file_path.trim_matches(|c| c == '\'' || c == ' '))?;
    let mut a = 1;
}

