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
}
