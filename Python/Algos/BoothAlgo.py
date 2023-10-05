class Booth:
    def __init__(self, multiplicand: int, multiplier: int):
        self.mm = multiplicand
        self.qq = multiplier
        self.size = self.get_size()
        self.m = self.dectobin(self.mm)
        self.subm = self.twoscomp(self.m)
        self.q = self.dectobin(self.qq)
        self.qo = self.q[-1]
        self.a = "0" * self.size
        self.q_1 = "0"
        self.count = self.size

    def twoscomp(self, num: str) -> str:
        num = list(num)
        for i in range(len(num)):
            if num[i] == "1":
                num[i] = "0"
            else:
                num[i] = "1"
        bincomp = bin(int("".join(num), 2) + int("1", 2))[2:]
        return bincomp[-self.size :]

    def dectobin(self, num: int) -> str:
        binarystr = bin(num)[2:]
        return binarystr.zfill(self.size)

    def add(self, a: str, m: str):
        return (bin(int(a, 2) + int(m, 2))[2:])[-self.size :]

    def get_size(self) -> int:
        sizem = len(bin(self.mm)) - 2
        sizeq = len(bin(self.qq)) - 2
        return max(sizem, sizeq) + 1

    def asr(self):
        shift = self.a + self.q
        shift = shift[0] + shift[0 : self.size() * 2 - 1]
        self.a = shift[: self.size()]
        self.q = shift[self.size() :]

    def __repr__(self, remark):
        print(f"> {self.a}\t\t{self.q}\t\t{self.q_1}\t\t{self.count}\t\t{remark}")

    def algo(self):
        indent = self.size
        print("> A".rjust(indent - 1) + "\t\t", end="")
        print("Q".rjust(indent - 1) + "\t\t", end="")
        print("Q_1".rjust(indent - 3) + "\t\t", end="")
        print("Count".rjust(indent - 5) + "\t\t", end="")
        print("Rem".rjust(indent - 5) + "\t\t")

        while self.count != 0:
            self.q0 = self.q[-1]
            if self.q0 == "1" and self.q_1 == "0":
                self.a = self.add(self.a, self.subm)
                self.__repr__("A = A-M")
            elif self.qo == "0" and self.q_1 == "1":
                self.a = self.add(self.a, self.m)
                self.__repr__("A = A+M")
            else:
                pass
            self.asr()
            self.__repr__("ASR")
            self.count -= 1


booth = Booth(7, -3)
booth.algo()
