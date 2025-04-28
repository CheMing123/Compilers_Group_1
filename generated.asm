section .text
  global _start

_start:
  mov rax, 60
  add rdi, 1
  add rdi, 1
  syscall
