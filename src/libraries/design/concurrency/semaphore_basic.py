import threading


class Semaphore:
    def __init__(self, available):
        self.cv = threading.Condition()
        self.MAX = available
        self.taken = 0

    def acquire(self):
        self.cv.acquire()
        while self.taken == self.MAX:
            self.cv.wait()
        self.taken += 1
        self.cv.release()

    def release(self):
        self.cv.acquire()
        self.taken -= 1
        self.cv.notify()
        self.cv.release()
