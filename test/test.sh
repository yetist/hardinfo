
DATADER=`pwd`

do_test() {
    ARCH="$1"
    CPUINFO="$DATADER/$2"
    cmake .. -DOVRARCH=$ARCH -DOVRCPUINFO=\"$CPUINFO\"
    make
}

#do_test x86 data/x86_pent_cpuinfo
#do_test x86 data/x86_amdr7_cpuinfo
#do_test ppc data/ppc_g5_cpuinfo
#do_test ppc data/power8_cpuinfo
#do_test arm data/arm_rpi3_aarch64_cpuinfo
do_test sparc data/sparc_m7_cpuinfo