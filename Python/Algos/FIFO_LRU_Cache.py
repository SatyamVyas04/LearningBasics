class FIFO:
    def __init__(self, string: str, size_of_cache: int):
        self.string = string
        self.arr = string.split()
        self.length_of_exp = self.arr.__len__()
        self.size_of_cache = size_of_cache
        self.cache = ["_"] * self.size_of_cache
        self.ages = [0] * self.size_of_cache
        self.oldest_location_ptr = -1
        self.hits = 0
        self.hitflag = False

    def display_cache(self):
        print("Cache: [ " + " | ".join(self.cache) + " ] <- CacheMEM")
        print(
            "PTR:   [ "
            + " " * self.oldest_location_ptr * 4
            + "\u2191"
            + " " * (self.size_of_cache - self.oldest_location_ptr - 1) * 4
            + " ] <- ToBeReplaced",
            end=" ",
        )
        if self.hitflag:
            print(f"<- HIT No. {self.hits}\n")
        else:
            print("\n")

    def algo(self):
        print(" FIFO ALGORITHM ".center(50, "-"))
        for index in range(self.length_of_exp):
            i = self.arr[index]
            if i in self.cache:
                hit_index = self.cache.index(i)
                self.hit_updations(hit_index)
            elif i not in self.cache and self.cache.count("_")>0:
                self.age_increment()
                self.cache[self.cache.index("_")] = i
                self.ages[self.ages.index(0)] = 1
                self.oldest_location_ptr == 0
                self.hitflag = False
            else:  # Cache Replacing Algo
                self.cache[self.oldest_location_ptr] = i
                self.ages[self.oldest_location_ptr] = 1
                self.hitflag = False
            self.ptr_update()
            self.display_cache()
        print(">>> HITS: ", self.hits)
        print(">>> HIT RATIO: ", self.hits / self.length_of_exp)
        print("\n".ljust(50, "-") + "\n")

    def ptr_update(self):
        self.oldest_location_ptr = self.ages.index(max(self.ages))

    def hit_updations(self, i: int):
        self.hits += 1
        self.age_increment()
        self.hitflag = True

    def age_increment(self):
        for i in range(self.size_of_cache):
            if self.ages[i] != 0:
                self.ages[i] += 1


class LRU(FIFO):
    def hit_updations(self, i: int):
        self.hits += 1
        self.age_increment()
        self.ages[i] = 1
        self.hitflag = True


string = "6 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 5"
fifo = FIFO(string=string, size_of_cache=4)
fifo.algo()

lru = LRU(string=string, size_of_cache=4)
lru.algo()
