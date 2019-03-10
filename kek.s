.name "kek"
.comment "kek, really?"

start:
live %66
st r15, -30
kek:
live %66
add r13, r12, r15
st r1, -9
live %66
st r5, 50
fork %10
zjmp %:start
