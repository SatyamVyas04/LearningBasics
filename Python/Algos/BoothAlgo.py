class Booth:
    def __init__(self, multiplicand: int, multiplier: int):
        self.mm = multiplicand
        self.qq = multiplier
        self.size = self.get_size()
        self.ans = ''
        self.binans = 0
        
        if self.mm < 0:
            self.subm = self.dectobin(abs(self.mm))
            self.m = self.twoscomp(self.subm)
        else:
            self.m = self.dectobin(self.mm)
            self.subm = self.twoscomp(self.m)

        if self.qq < 0:
            self.q = self.dectobin(abs(self.qq))
            self.q = self.twoscomp(self.q)
        else:
            self.q = self.dectobin(self.qq)

        self.q0 = self.q[-1]
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
        return bincomp[-self.size :].zfill(self.size)

    def twoscompfin(self, num: str) -> str:
        num = list(num)
        for i in range(len(num)):
            if num[i] == "1":
                num[i] = "0"
            else:
                num[i] = "1"
        return bin(int("".join(num), 2) + int("1", 2))[2:].zfill(self.size * 2)

    def dectobin(self, num: int) -> str:
        binarystr = bin(num)[2:]
        return binarystr.zfill(self.size)

    def add(self, a: str, m: str):
        acc = int(a, 2)
        mul = int(m, 2)
        accnew = acc + mul
        return self.dectobin(accnew)[-self.size :]

    def get_size(self) -> int:
        sizem = len(bin(abs(self.mm))) - 2
        sizeq = len(bin(abs(self.qq))) - 2
        return max(sizem, sizeq) + 1

    def asr(self):
        shift = self.a + self.q
        shift = shift[0] + shift[: 2 * self.size - 1]
        self.a = shift[: self.size]
        self.q = shift[self.size :]

    def __repr__(self, remark):
        print(f"> {self.a}\t{self.q}\t{self.q_1}\t{self.count}\t{remark}")

    def algo(self):
        indent = self.size
        print("> A" + "\t", end="")
        print("Q" + "\t", end="")
        print("Q_1" + "\t", end="")
        print("Count" + "\t", end="")
        print("Remark" + "\t\t")

        self.__repr__("Initial")
        while self.count != 0:
            self.q0 = self.q[-1]
            self.__repr__("Current")
            if self.q0 == "1" and self.q_1 == "0":
                self.a = self.add(self.a, self.subm)
                self.__repr__("A = A - M")
            elif self.q0 == "0" and self.q_1 == "1":
                self.a = self.add(self.a, self.m)
                self.__repr__("A = A + M")
            else: 
                pass
            self.asr()
            self.q_1 = self.q0
            self.__repr__("ASR")
            print()
            self.count -= 1

        self.__repr__("Final")
        if self.qq * self.mm < 0:
            print("\n> ANS: " + self.a + self.q)
            print("> ANS Absolute Value: " + self.twoscompfin(self.a + self.q))
            self.ans = self.twoscompfin(self.a + self.q)
            self.binans = -int(self.ans, 2)
        else:
            print("\n> ANS: " + self.a + self.q)
            print("> ANS Absolute Value: " + self.a + self.q)
            self.ans = f'{self.a}{self.q}'
            self.binans = int(self.ans, 2)
        
        print(f">>>>>>> {self.binans}")
        print("\n")


booth = Booth(7, 8)
booth2 = Booth(7, -8)
booth3 = Booth(-7, 8)
booth4 = Booth(-3, -2)
booth.algo()
booth2.algo()
booth3.algo()
booth4.algo()
