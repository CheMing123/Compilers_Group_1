section .text
  global _start

_start:
  mov rax, 1
  push rax
  mov rbx, 1
  add rax, rbx
  push rax
  mov rax, 60
  pop rdi
  syscall
