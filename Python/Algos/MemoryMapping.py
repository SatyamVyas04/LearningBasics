import math


class MemMapping:
    def __init__(self, MemSize: int, CacheSize: int, BlockSize: int) -> None:
        self.mem_size = MemSize
        self.cache_size = CacheSize
        self.block_size = BlockSize
        self.number_blocks = self.mem_size // self.block_size
        self.number_lines = self.cache_size // self.block_size
        self.size_block_index = int(math.log(self.number_blocks, 2))
        self.size_cache_index = int(math.log(self.number_lines, 2))
        self.bi_arr = self.int_to_bin_loop(self.size_block_index)
        self.ci_arr = self.int_to_bin_loop(self.size_cache_index)

    def int_to_bin_loop(self, n: int) -> list[str]:
        arr = []
        for i in range(2**n):
            arr.append(bin(i)[2:].zfill(n))
        return arr

    def maps_to(self, block_index: str) -> None:
        if block_index in self.bi_arr:
            bitdiff = self.size_cache_index - self.size_block_index
            print(
                f"> {block_index} Block Index maps to {block_index[bitdiff:]} Cache Index\n"
            )
        else:
            print("> Out of Range Index!\n")

    def display_details(self) -> None:
        print("Details".center(50, "-"))
        print("> Memory Size:", self.mem_size)
        print("> Cache Size:", self.cache_size)
        print("> Block Size:", self.block_size)
        print("> Number of Blocks:", self.number_blocks)
        print("> Number of Lines:", self.number_lines)
        print("> Size of Block Index:", self.size_block_index)
        print("> Size of Cache Index:", self.size_cache_index)
        print("\nHere are the Current Mappings of Blocks on Lines: ")
        for i in range(self.number_lines):
            print(f"> {self.ci_arr[i]}: ", end="")
            for j in range(i, self.number_blocks, 4):
                print(self.bi_arr[j], end=" ")
            print()
        print("-".center(50, "-"))


mem = MemMapping(MemSize=128, CacheSize=32, BlockSize=8)
print("Searching Key Mappings: ")
mem.maps_to("1111")
mem.maps_to("0000")
mem.maps_to("0101")
mem.maps_to("0111")
mem.maps_to("11111")
mem.display_details()
