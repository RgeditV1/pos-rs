fn main() {
    cxx_build::bridge("src/backend/lib.rs")
        .flag_if_supported("-std=c++20")
        .compile("pos_backend_bridge");

    println!("cargo:rerun-if-changed=src/backend/lib.rs");
}
