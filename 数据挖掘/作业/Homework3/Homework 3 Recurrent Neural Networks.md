# Homework 3: Recurrent Neural Networks

Student Name:孙肖冉         Student ID：16340198

## 1 Exercise 1: Backpropagation through Time Backpropagation through Time

(a) 



$$y_i = \sigma(W_i^\top x)$$

$$\frac{\partial y_i}{\partial x_j} = \frac{\partial  \sigma(W_i^\top x)}{\partial x_j} = \sigma^{'}( W_i^\top x)\frac{\partial(W_i^\top x)}{\partial x_j}=\sigma^{'}( W_i^\top x)\frac{\partial(\sum_{k=1}^{d}{W{ik}\cdot x_k})}{\partial x_j}$$
$$=\sigma^{'}( W_i^\top x)W_{ij}$$


$$\frac{\partial y}{\partial x } = \begin{pmatrix} &  \sigma^{'}( W_i^\top x)W_{11} &  ...&  \sigma^{'}( W_i^\top x)W_{1d}  & \\  & ...&...&... & \\  & \sigma^{'}( W_i^\top x)W_{n1} & ... & \sigma^{'}( W_i^\top x)W_{nd}\end{pmatrix} = diag(\sigma^{'})W$$

(b)

$$\frac{\partial L}{\partial W} = \frac{\partial \sum_{t=0}^{T}L_t}{\partial W} = \sum_{t=0}^{T}\frac{\partial L_t}{\partial W} = \sum_{t=0}^{T}\frac{\partial L_t}{\partial h_t}\frac{\partial h_t}{\partial W}$$

$$h_t \ depends \ on \ h_k\  (k ≤ t)\ , \ h_k\ depends\  on\  W$$

$$\frac{\partial L_t}{\partial h_t}\frac{\partial h_t}{\partial W}= \sum_{t=0}^{T}\sum_{k=0}^{t}\frac{\partial L_t}{\partial h_t}\frac{\partial h_t}{\partial h_k}\frac{\partial h_k}{\partial W}$$

$$\frac{\partial h_t}{\partial h_k} = \prod_{i=k+1}^t\frac{\partial h_i}{\partial h_{i-1}}$$

$$\frac{\partial L}{\partial W} = \sum_{t=0}^{T}\sum_{k=0}^{t}\frac{\partial L_t}{\partial h_t} \prod_{i=k+1}^t\frac{\partial h_i}{\partial h_{i-1}}\frac{\partial h_K}{\partial w}$$
$$=   \sum_{t=0}^{T}\sum_{k=1}^{t}\frac{\partial l_t}{\partial h_t}\frac{\partial h_t}{\partial h_k}\frac{\partial h_k}{\partial W}$$


## 2 Exercise 2: Vanishing/Exploding Gradients in RNNs

(a)


$$Assume\ T = 3 \ ; t = 0,1,2,3$$

$$\frac{\partial L}{\partial W}  = \frac{\partial l_0}{\partial h_0} \frac{\partial h_0}{\partial h_0}  \frac{\partial h_0}{\partial w}   (t = 0)$$

$$+  \frac{\partial l_1}{\partial h_1}  \frac{\partial h_1}{\partial h_0}  \frac{\partial h_0}{\partial W} + \frac{\partial l_1}{\partial h_1} \frac{\partial h_1}{\partial h_1}   \frac{\partial h_1}{\partial W} (t=1)​$$

$$+  \frac{\partial l_2}{\partial h_2}  \frac{\partial h_2}{\partial h_0}  \frac{\partial h_0}{\partial W} + \frac{\partial l_2}{\partial h_2} \frac{\partial h_2}{\partial h_1}   \frac{\partial h_1}{\partial W}+\frac{\partial l_2}{\partial h_2}  \frac{\partial h_2}{\partial h_0}  \frac{\partial h_0}{\partial W} (t=2)$$

$$+  \frac{\partial L_3}{\partial h_3}  \frac{\partial h_3}{\partial h_0}  \frac{\partial h_0}{\partial W} + \frac{\partial l_3}{\partial h_3} \frac{\partial h_3}{\partial h_1}   \frac{\partial h_1}{\partial W}+  \frac{\partial l_3}{\partial h_3}  \frac{\partial h_3}{\partial h_2}  \frac{\partial h_2}{\partial W}+  \frac{\partial l_3}{\partial h_3}  \frac{\partial h_3}{\partial h_3}  \frac{\partial h_3}{\partial W} (t=3)$$

$$=   \frac{\partial l_0}{\partial h_0}  \frac{\partial h_0}{\partial W} +  \frac{\partial l_1}{\partial h_1}\cdot diag(\sigma^{'})W\cdot \frac{\partial h_0}{\partial W}+ \frac{\partial l_1}{\partial h_1} \frac{\partial h_1}{\partial W}$$

$$+  \frac{\partial l_2}{\partial h_2}\cdot [ diag(\sigma^{'})W]^{2}\cdot \frac{\partial h_0}{\partial W}+\frac{\partial l_2}{\partial h_1}\cdot diag(\sigma^{'})W\cdot \frac{\partial h_0}{\partial W}+\frac{\partial l_2}{\partial h_2}\frac{\partial h_2}{\partial W}$$
$$+\frac{\partial l_3}{\partial h_3}\cdot[ diag(\sigma^{'})W]^{3}\cdot \frac{\partial h_0}{\partial W}+\frac{\partial l_3}{\partial h_3}\cdot[ diag(\sigma^{'})W]^{2}\cdot \frac{\partial h_0}{\partial W}+\frac{\partial l_3}{\partial h_3}\cdot diag(\sigma^{'})W\cdot \frac{\partial h_0}{\partial W}\\+\frac{\partial l_3}{\partial h_3}\cdot diag(\sigma^{'})W\cdot \frac{\partial h_0}{\partial W}+\frac{\partial l_3}{\partial h_3} \frac{\partial h_0}{\partial W}$$

(b)

$$Assume\ Q = (Q_1,\ ...,\ Q_n)$$
$$then \ MQ = (MQ_1,\ ...,\ MQ_n) \ , \ (λ_1Q_1,\ ...,\  λ_nQ_n） = （Q_1,\ ...,\ Q_n）\begin{pmatrix} & λ_1&  ...&  0  & \\  & ...&...&... & \\  &0 & ... & \ λ_n\end{pmatrix} = Q\wedge$$
$$thus\ M = Q \wedge Q^{-1}$$

$$ we \ make\ a\ hypothesie\ :\  M^{k} = Q \wedge ^{k} Q^{-1}$$

$$then\ M^{k+1} =( Q\wedge Q^{-1}) ( Q \wedge ^{k} Q^{-1})= Q\wedge Q^{-1}Q \wedge ^{k} Q^{-1} $$

$$= Q \wedge \cdot \wedge^{k}Q^{-1} = Q\wedge^{k+1}Q^{-1}$$

$$so \ we \ can\  get \ that:$$
$$
\prod_{i=1}^n M\  can\  be\  represented\  as : M^n = Q\wedge^{n} Q^{-1}
$$

(c)

$$Calculate \ W^{30}\ : \ W^{30} =  \begin{pmatrix} & 0& 0   \\&0 &0 \end{pmatrix}$$



$$ three\ situations:$$

$$\prod_{i=1}^t diag(\sigma^{'})W = diag(\sigma^{'})^{n}\cdot W^{n}$$
$$W^{n} = Q\wedge^nQ^{-1} => \wedge^{n} = \begin{pmatrix} & λ_1^{n}&  ...&  0  & \\  & ...&...&... & \\  &0 & ... & \ λ_n^{n}\end{pmatrix}$$

$$ {\lim_{i \to \infty}λ_i} =\left\{\begin{aligned}\infty &  & λ_i > 1 \\1 &  & λ_i = 1 \\0 &  & λ_i < 1\end{aligned}\right.$$



## 3 Exercise 3: LSTMs

$$
f_t = \sigma(W_fh_{t-1}+U_fx_t)\\
i_t = \sigma(W_ih_{t-1}+U_ix_i)\\
o_t = \sigma(W_oh_{t-1}+U_ox_t)\\
\tilde{C_t} = tanh(W_ch_{t-1}+U_cx_t)\\
C_t = f_t\bigodot C_{t-1}+i_t\bigodot \tilde{C_t}\\
h_t = o_t \bigodot tnah(C_t)\\
$$

(a)

$$ f_t $$ :  forget  the old subject , remember a new subject 

$$i_t$$ :  selectively update the state based on new inpute

$$o_t$$ :  output is the filtered version of the cell state

(b)*
$$
f_t ,\ i_t, \ o_t \ are\  positive.
$$

(c)*

$$ \frac{\partial C_t}{\partial C_k} ≈ 1$$

$$ \frac{\partial C_t}{\partial C_k} =\prod_{i=k+1}^t \frac{\partial C_t}{\partial C_{t-1}} $$

$$ \frac{\partial C_t}{\partial C_{t-1}} = \frac{\partial }{\partial C_{t-1}}(f_t\bigodot C_{t-1}+i_t\cdot tanh(W_c h_{t-1}+U_cx_t))$$

$$=\frac{\partial f_t}{\partial C_{t-1}}\bigodot C_{t-1}+ f_t\cdot  \frac{\partial C_{t-1}}{\partial C_{t-1}}+ \frac{\partial i_t}{\partial C_{t-1}}\bigodot \tilde{C_t}+i_t\bigodot \frac{\partial \tilde{C_t}}{\partial C_{t-1}}$$

$$= \frac{\partial f_t}{\partial h_{t-1}}\cdot \frac{\partial h_t}{\partial C_{t-1}}\bigodot C_{t-1}+f_t+\frac{\partial i_t}{\partial h_{t-1}}\frac{\partial h_{t-1}}{\partial C_{t-1}}\bigodot \tilde{C_t}+i_t\bigodot \frac{\partial \tilde{C_t}}{\partial h_{t-1}}\frac{\partial h_{t-1}}{\partial C_{t-1}} $$

$$=\sigma^{‘}W_f\cdot [ \frac{\partial o_{t-1}}{\partial C_{t-1}}\bigodot C_{t-1}+tanh^{’}]\bigodot C_{t-1}+\sigma^{‘}W_i\cdot [ \frac{\partial o_{t-1}}{\partial C_{t-1}}\bigodot C_{t-1}+tanh^{’}]\bigodot\tilde C_{t}$$$$+i_t\bigodot tanh^{‘} [ \frac{\partial o_{t-1}}{\partial C_{t-1}}\bigodot C_{t-1}+tanh^{’}]$$



