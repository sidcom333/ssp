import subprocess

def assemble_and_run(assembly_code):
    # Save the assembly code to a file
    with open("temp.asm", "w") as file:
        file.write(assembly_code)

    # Assemble the code using NASM
    subprocess.run(["nasm", "-f", "elf", "temp.asm"])

    # Link the object file to create an executable
    subprocess.run(["gcc", "-m32", "-o", "temp", "temp.o"])

    # Run the executable
    subprocess.run(["./temp"])

    # Clean up temporary files
    subprocess.run(["rm", "temp.asm", "temp.o", "temp"])

# Example assembly code (Hello World for x86_64 Linux)
assembly_code = """
section .data
    hello db 'Hello, World!',0

section .text
    global _start

_start:
    ; write the string to stdout
    mov eax, 4
    mov ebx, 1
    mov ecx, hello
    mov edx, 13
    int 0x80

    ; exit
    mov eax, 1
    xor ebx, ebx
    int 0x80
"""

assemble_and_run(assembly_code)
