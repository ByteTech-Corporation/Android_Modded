#include <filedefs.h>
#include <fastboot_main.h>
/// @brief Fastboot()
void Fastboot()
{
    printf("fastboot mode !!, FASTBOOT Tonga-Custom");
    /* Fastboot */
    void fastbootd();
    {
        enum FastbootCommands {
            const OEMPartition="fastboot oem partition {PARTITION}, {args: preserve-no-root/>NO_DEL_root, no-preserve-root/>DEL_root, rebootMode/>,recovery>/efs/bmd/recovery,edl>/efs/bmd/edl,normal>*,rescue>/efs/bmd/rescue,odinmode>/efs/bmd/ODIN}"
            const Reboot="fastboot reboot odin, recovery, edl, rescue, normal"
            const RootCMDs="fastboot oem rootpms">"/efs/pms"
            const Custom="fastboot custom">"/efs/fastbootd/custom"
        }
    }
}

static void Fastboot.main();
{
    printf("main fastbootd !!")
}
