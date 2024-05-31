#include <../include/multiboot2.h> //<multiboot2.h>

#include "../include/libc/stdint.h"  //"libc/stdint.h"
#include "../include/libc/stddef.h"  //"libc/stddef.h"
#include "../include/libc/stdbool.h" ///"libc/stdbool.h"
#include "../include/libc/system.h"  ///"libc/system.h"

#include "../include/pit.h"               //"pit.h"
#include "../include/common.h"            //"common.h"
#include "../include/descriptor_tables.h" //"descriptor_tables.h"
#include "../include/interrupts.h"        //interrupts.h"
#include "../include/monitor.h"           //"monitor.h"
#include "../include/memory/memory.h"     //"memory/memory.h"

// Structure to hold multiboot information.
struct multiboot_info
{
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

// Forward declaration for the C++ kernel main function.
int kernel_main();

// End of the kernel image, defined elsewhere.
extern uint32_t end;

// Main entry point for the kernel, called from boot code.
// magic: The multiboot magic number, should be MULTIBOOT2_BOOTLOADER_MAGIC.
// mb_info_addr: Pointer to the multiboot information structure.
int kernel_main_c(uint32_t magic, struct multiboot_info *mb_info_addr)
{
    // Initialize the monitor (screen output)
    monitor_initialize();

    // Initialize the Global Descriptor Table (GDT).
    init_gdt();

    // Initialize the Interrupt Descriptor Table (IDT).
    init_idt();

    // Initialize the hardware interrupts.
    init_irq();

    // Initialize the kernel's memory manager using the end address of the kernel.
    init_kernel_memory(&end);

    // Initialize paging for memory management.
    init_paging();

    // Print memory information.
    print_memory_layout();

    init_pit();

    // Print a hello world message.
    printf("Hello World!\n");

    // Call the C++ main function of the kernel.
    return kernel_main();
}
