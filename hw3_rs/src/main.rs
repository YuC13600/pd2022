use std::io;

fn main() {
    loop {
        let mut buffer = String::new();
        let bytes = io::stdin()
            .read_line(&mut buffer)
            .expect("Error reading");
        if bytes == 0 {
            return;
        }
        let arr: Vec<i32> = buffer.trim().split(' ')
            .map(|x| x.parse::<i32>().unwrap()).collect();
        // println!("{} {} {}", arr[0], arr[1], arr[2]);
        println!("{}", chk(arr));
    }
}
fn chk(arr: Vec<i32>) -> String{
    let (a, b, c) = (arr[0], arr[1], arr[2]);

    //IS
    if a == b {
        return "IS".to_string()
    }

    //IM
    if b/8 != c/8 && b%8 != c%8 {
        return "IM".to_string()
    }
    if a==c || b==c {
        return "IM".to_string()
    }
    if b/8 == c/8 && b/8 == a/8 {
        if (b%8 > a%8 && a%8 > c%8) || (b%8 < a%8 && a%8 < b%8) {
            return "IM".to_string()
        }
    }
    if b%8 == c%8 && b%8 == a%8 {
        if (b/8 > a/8 && a/8 > c/8) || (b/8 < a/8 && a/8 < c/8) {
            return "IM".to_string();
        }
    }

    //MNA
    if a/8 == c/8 {
        if a%8 == c%8+1 || a%8 == c%8-1 {
            return "MNA".to_string()
        }
    }
    if a%8 == c%8 {
        if a/8 == c/8+1 || a/8 == c/8-1 {
            return "MNA".to_string()
        }
    }

    //A
    if a/8+1 != c/8 && a/8+1 < 8 {
        return "A".to_string()
    }
    if a/8-1 != c/8 && a/8-1 >= 0 {
        return "A".to_string()
    }
    if a%8+1 != c%8 && a%8+1 < 8 {
        return "A".to_string()
    }
    if a%8-1 != c%8 && a%8-1 >= 0 {
        return "A".to_string()
    }
    
    "S".to_string()
}