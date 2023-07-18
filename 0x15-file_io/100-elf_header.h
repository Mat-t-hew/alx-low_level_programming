#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <stdint.h>

#define ELF_HEADER_SIZE 64

/**
 * Elf64_Ehdr - ELF header structure
 *
 * This structure represents the ELF header format for 64-bit architectures.
 * It contains various fields providing information about the ELF file.
 */

typedef struct
{
	unsigned char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_error(const char *message);
void print_magic(const unsigned char *e_ident);
void print_class(const unsigned char *e_ident);
void print_data(const unsigned char *e_ident);
void print_version(const unsigned char *e_ident);
void print_os_abi(const unsigned char *e_ident);
void print_abi_version(const unsigned char *e_ident);
void print_type(uint16_t e_type);
void print_entry_point(uint64_t e_entry);
void print_elf_header(const char *file_name);

#endif /* ELF_HEADER_H */
