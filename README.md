# MAVLink Fuzzing Target

This project is a modified version of the original MAVLink library, with an added sample binary that can be run with AFL++.


### How to build

To install the minimal MAVLink environment on Ubuntu LTS 20.04 or 22.04, enter the following on a terminal:

```bash
# Dependencies
sudo apt install python3-pip

# Clone mavlink into the directory of your choice
git clone https://github.com/WUSTL-CSPL/mavlink_fuzz_CSE569.git
cd mavlink

python3 -m pip install -r pymavlink/requirements.txt
```

Build Mavlink:
```bash
cmake -Bbuild -H. -DCMAKE_INSTALL_PREFIX=install
cmake --build build --target install
```

We have provided an example program that tests the parsing functionality (i.e., `mavlink_parse_char()`) in the MAVLink library.  

To build the example, navigate to the example directory and specify the local installation directory during compilation:
```bash
cd examples/c
cmake -Bbuild -H. -DCMAKE_PREFIX_PATH=$(pwd)/../../install
cmake --build build
```

The CMake file (i.e., **CMakeLists.txt**) is already configured to compile with AFL flags. You can inspect it and make modifications to meet your requirements.

### How to run with AFL

To run it with AFL, we created a directory at `examples/c/input`, which you can use as the input for fuzzing. Run the following command:  

```bash
AFL_SKIP_CPUFREQ=1 AFL_USE_ASAN=1 afl-fuzz -i input -o output -- ./build/udp_example @@
```

This will start AFL, and you should see its interface running.  

If you encounter any issues, try running this command:  

```bash
echo core | sudo tee /proc/sys/kernel/core_pattern
```


### How to proceed next

The current framework is minimal for fuzzing and may not effectively explore the functions in the MAVLink library. You can review the source code in `udp_example.c` and `CMakeLists.txt` to improve AFL++'s ability to explore the target library more thoroughly.