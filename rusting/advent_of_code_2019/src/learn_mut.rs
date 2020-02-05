
fn r(n: i32) -> i32 {
    if n > 0{
        return 0 // or write the else block    
    } // else{ 1 }
    1
}
use std::cell::Cell;
struct SomeStruct {
    regular_field: u8,
    special_field: Cell<u8>,
}
fn cell_test(){
    let my_struct = SomeStruct{
        regular_field: 0,
        special_field: Cell::new(1),
    };
    let new_val = 100;
    //my_struct.special_field.set(new_val);
    assert_eq!(my_struct.special_field.get(), new_val);
}
use std::cell::RefCell;
use std::thread;


fn refcell_test(){


    let result = thread::spawn(move || {
        let c = RefCell::new(5);
        //let m = c.borrow();
        //println!("{}", m);
        let b = c.borrow_mut();
    }).join();
    //assert!(result.is_err());
    // RefCell has dynamically borrow check!
    // Cell<T>适用于实现了Copy的类型（复制语义）get/set
    // REfCell<T>适用于未实现Copy的类型（移动语义）borrow/borrow_mut
    let c = RefCell::new(5);
    *c.borrow_mut() = 7;
    assert_eq!(7, *c.borrow());

    let x = RefCell::new(vec![1,2,3]);
    println!("{:?}", x.borrow());
    x.borrow_mut().push(4);
    println!("{:?}", x.borrow());
}
struct Foo {
    x: u32
}
fn print_foo(foo: &Foo){
    println!("x={}", foo.x);
}
fn change_foo(foo: &mut Foo){
    foo.x = foo.x * 2;    
    println!("x={}", foo.x);
}
fn main(){
    let mut s = String::from("hello");
    let r1 = &mut s;
    //let r2 = &mut s; //ERR: mutable var cannot have another name
    //let r2 = &s;
    println!("{}", r1);
    let x = 1;
    let y = &x;
    //let y = &mut x; //ERR: immutable var cannot be borrowed
    println!("{}, {}", r1, y);
    let mut data = 1_i32; 
    //let p : &i32 = &data;
    let q = &mut data;
    //data = 10; ERR
    //println!("{}", *p); //这个时候由于使用到不可变p引用，所以可变q引用一点也不能存在，反之亦然
    *q = 10;
    println!("{}", data);
    let mut foo = Foo{x:1}; // T inherited mutability
    let b_foo = &foo;
    let mb_foo = &mut foo;
    //print_foo(b_foo);
    //print_foo(mb_foo); // either &Foo or &mut Foo
    change_foo(mb_foo);

    //cell_test(); // 单线程的内部可变性, std::cell模块中的Cell<T> RefCell<T>是两个提供内部可变性的共享可变容器。
    // Interior mutability 如果某个类型的内部状态可以通过对它的共享引用来更改，则它具有内部可变性。
    // Cell<T> RefCell<T>是被 UnsafeCell<T> 内部可变性的核心原语 包装起来的。
    /*
    UnsafeCell<T>类型是通过共享引用持有可变数据的唯一合法方式。源码如下：
    #[lang = "unsafe_cell"]
    #[stable(feature = "rust1", since = "1.0.0")]
    #[repr(transparent)]
    pub struct UnsafeCell<T: ?Sized> {
        value: T,
    }

    pub const fn get(&self) -> *mut T {
        self as *const UnsafeCell<T> as *const T as *mut T
    }  
    */
    refcell_test();
    // Mutex<T> RwLock<T> 多线程的内部可变性
    // 共享不可变，可变不共享
}