/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** get_name_symbol
*/

#include "ftrace.h"
#include <fcntl.h>

void find_symbol_table(Elf *elf, GElf_Shdr *shdr, Elf_Scn **scn)
{
    while ((*scn = elf_nextscn(elf, *scn))) {
        gelf_getshdr(*scn, shdr);
        if (shdr->sh_type == SHT_SYMTAB)
            return;
    }
}

char *addr_not_found(char *name, long long unsigned addr)
{
    char *tmp = calloc(1, strlen(name) + 25);

    if (!tmp)
        return (NULL);
    snprintf(tmp, 30, "func_0x%llx@%s", addr, name);
    return (tmp);
}

static char *get_name(Elf *elf, Elf_Scn *elf_scn, GElf_Shdr elf_shdr, \
long long unsigned addr)
{
    Elf_Data *data = elf_getdata(elf_scn, NULL);
    GElf_Sym sym = {0};

    if (elf_shdr.sh_entsize == 0)
        return (NULL);
    for (size_t i = 0; i < elf_shdr.sh_size / elf_shdr.sh_entsize;
    i++) {
        gelf_getsym(data, i, &sym);
        if (sym.st_value == addr)
            return (strdup(elf_strptr(elf, elf_shdr.sh_link,
            sym.st_name)));
    }
    return (NULL);
}

char *get_name_symbol(char *path, long long unsigned addr)
{
    int fd = open(path, O_RDONLY);
    Elf *elf = NULL;
    Elf_Scn *scn = NULL;
    GElf_Shdr shdr;
    char *name;

    elf_version(EV_CURRENT);
    if (fd == -1)
        return (NULL);
    elf = elf_begin(fd, ELF_C_READ, NULL);
    find_symbol_table(elf, &shdr, &scn);
    name = get_name(elf, scn, shdr, addr);
    elf_end(elf);
    close(fd);
    return (name);
}

char *get_name_from_info(ftrace_info_t *info, unsigned long long address)
{
    char *name = get_name(info->elf, info->elf_scn, info->elf_shdr, address);

    return (name);
}
