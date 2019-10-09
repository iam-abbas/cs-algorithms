#lang racket

;; Reference: Project Euler (https://projecteuler.net/problem=4)

(define (rev-string str)
  (list->string (reverse (string->list str))))

(define (palindrome? x)
    (equal? (number->string x) (rev-string (number->string x))))

(define (largest-palindrome-triplet)
  (apply max
         (for*/list ([a (in-range 999 100 -1)]
                     [b (in-range a 100 -1)]
                     #:when (palindrome? (* a b)))
           (* a b))))

(largest-palindrome-triplet)

