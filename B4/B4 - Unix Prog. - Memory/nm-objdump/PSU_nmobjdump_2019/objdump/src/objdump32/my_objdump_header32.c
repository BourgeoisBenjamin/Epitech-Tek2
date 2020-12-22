/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** TODO: add description
*/

#include "../../include/objdump.h"

char *objdump_get_architecture32(uint16_t identifier)
{
    emachine_t arch_identifier[] = {
        {EM_NONE, "UNKNOWN!"}, {EM_M32, "AT&T WE 32100"},
        {EM_SPARC, "Sun Microsystems SPARC"}, {EM_386, "i386"},
        {EM_68K, "Motorola 68000"}, {EM_88K, "Motorola 88000"},
        {EM_860, "Intel 80860"}, {EM_MIPS, "MIPS RS3000"},
        {EM_PARISC, "HP/PA"},
        {EM_SPARC32PLUS, "SPARC with enhanced instruction set"},
        {EM_PPC, "PowerPC"}, {EM_PPC64, "PowerPC 64-bit"},
        {EM_S390, "IBM S/390"}, {EM_ARM, "Advanced RISC Machines"},
        {EM_SH, "Renesas SuperH"}, {EM_SPARCV9, "SPARC v9 64-bit"},
        {EM_IA_64, "Intel Itanium"}, {EM_386, "i386"},
        {EM_X86_64, "i386:x86-64"}, {EM_VAX, "DEC Vax"},
        {0, NULL}
    };
    for (int i = 0; arch_identifier[i].name != NULL; i++) {
        if (arch_identifier[i].identifier == identifier)
            return (arch_identifier[i].name);
    }
    return (arch_identifier[0].name);
}

uint32_t get_flags32(elffile32_t *file)
{
    uint32_t flags = BFD_NO_FLAGS;
    if (file->ehdr->e_type == ET_EXEC)
        flags += EXEC_P;
    if (file->ehdr->e_type == ET_DYN)
        flags += DYNAMIC;
    if (file->ehdr->e_type == ET_REL)
        flags += HAS_RELOC;
    if (file->ehdr->e_phnum)
        flags += D_PAGED;
    for (int i = 0; i < file->ehdr->e_shnum; i++) {
        if (file->shdr[i].sh_type == SHT_SYMTAB || file->shdr[i].sh_type ==
        SHT_DYNSYM) {
            flags += HAS_SYMS;
            break;
        }
    }
    return flags;
}

void objdump_print_flags32(uint32_t e_flags)
{
    int flags = 0;
    eflags_t eflags_identifier[] = {{BFD_NO_FLAGS, "BFD_NO_FLAGS"},
        {HAS_RELOC, "HAS_RELOC"}, {EXEC_P, "EXEC_P"}, {HAS_LINENO, "HAS_LINEO"},
        {HAS_DEBUG, "HAS_DEBUG"}, {HAS_SYMS, "HAS_SYMS"},
        {HAS_LOCALS, "HAS_LOCALS"}, {DYNAMIC, "DYNAMIC"}, {WP_TEXT, "WP_TEXT"},
        {D_PAGED, "D_PAGED"}, {0, NULL}};

    for (int i = 0; eflags_identifier[i].name != NULL; i++) {
        if (e_flags & eflags_identifier[i].identifier && flags == 0) {
            printf("%s", eflags_identifier[i].name);
            flags++;
        } else if (e_flags & eflags_identifier[i].identifier) {
            printf(", %s", eflags_identifier[i].name);
            flags++;
        }
    }
    if (flags) printf("\n");
}

void objdump_display_header32(elffile32_t *file)
{
    uint32_t flags = get_flags32(file);
    printf("%s:     file format elf32-i386\n", file->filename);
    printf("architecture: %s, flags 0x%08x:\n", objdump_get_architecture32
    (file->ehdr->e_machine), flags);
    objdump_print_flags32(flags);
    printf("start address 0x%08x\n", file->ehdr->e_entry);
}