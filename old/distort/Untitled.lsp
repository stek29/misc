(setf testf (s-read "./test.wav"))


(defun string-to-list (string)
"Convert a string into a list"
  (read (make-string-input-stream (format nil "(~a)" string))))

(setf hzlist "1")
(setf depthlist "30")

(setf hzlist (string-to-list hzlist))
(setf depthlist (string-to-list depthlist))

(defun GetBreakpoints (type data)
  (do ((i (1- (length data)) (1- i))
       (bp ())
       (intval (/ 1.0 (1- (length data)))))
    ((< i 0) (cdr bp))
  (if (= type 0)  ;Hz
      (setf val (checkHz (nth i data)))
      (setf val (checkdepth (nth i data))))
  (push val bp)
  (push intval bp)))

(defun env (type data)
  (cond
    ((and (= (length data) 1)(= type 0))  ;Hz
      (checkHz (first data)))
    ((= (length data) 1)  ;depth
      (checkdepth (first data)))
    (T (setf bp (GetBreakpoints type data))
       (pwlvr-list bp))))

(defun checkHz (x) x)

(defun checkdepth (x)
   (power (/ x 100.0) 3.0))

(defun soundlen (snd)
  (/ (snd-length snd (round 1e18)) (snd-srate snd)))

(defun vibrato (sig)
  (let ((hz (env 0 hzlist))
        (depth (env 1 depthlist)))
    (setf map
      (integrate
        (sum (diff 1 depth)
             (mult depth
                   (sum 5 (hzosc hz))))))
    (snd-compose sig map)))
;(s-plot (hzosc (env 1 hzlist)))
(defun vibrato (sig)
  (let ((hz (env 0 hzlist))
        (depth (env 1 depthlist)))
    (setf map
      (integrate
        (sum (diff 1 depth)
             (mult depth
                   (sum 5 (hzosc hz))))))
    map))

(s-plot (vibrato 0) 10)

;(pprint (soundlen (osc 60 1.5)))