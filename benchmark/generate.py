class File():

    def __init__(self, path: str, name: str, mode: str) -> None:

        self.__path: str = path
        self.__name: str = name
        self.__mode: str = mode

        self.__dir: str = self.__path + self.__name

    def save(self, value: int, fr: int, to: int) -> None:

        with open(self.__dir, self.__mode) as f:

            f.write("list" + "\n")
            f.write(str(value) + "\n")
            f.write(str(100) + "\n")
            f.write("Find" + "\n")
            f.write(str(fr) + "\n")
            f.write(str(to) + "\n")
            f.write("Khan" + "\n")
            f.write("Tarjan" + "\n")
            f.write("Exit" + "\n")

class Generator():

    def __init__(self, n: int) -> None:

        self.__n: int = n

    def generateToPath(self, path: str) -> str:

        for i in range(1, self.__n + 1):

            name: str = str(i)

            if i <= 1:
                fr: int = 0
            else:
                fr: int = pow(2, i) // 2

            file: File = File(path, name, 'w')

            file.save(pow(2, i), fr, pow(2, i) - 1)

def main() -> None:

    generator: Generator = Generator(19)

    generator.generateToPath('benchmark_results/')

if __name__ == '__main__':
    main()