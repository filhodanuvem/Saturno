temfilho(jose,joao).
temfilho(jose,ana).
temfilho(maria,ana).
temfilho(maria,joao).
temfilho(ana,helena).
temfilho(ana,joana).
temfilho(joao,mario).
temfilho(helena,carlos).
temfilho(mario,carlos).

masculino(mario).
masculino(jose).
masculino(joao).
masculino(carlos).

feminino(ana).
feminino(maria).
feminino(helena).

irmaogenerico(X,Y) :- temfilho(Z,X), temfilho(Z,Y), !.
irma(X,Y) :- irmaogenerico(X,Y), feminino(X).
irmao(X,Y):- irmaogenerico(X,Y), masculino(X).

mae(X,Y) :- temfilho(X,Z), feminino(X). 
pai(X,Y) :- temfilho(X,Z), masculino(X).

descendente(X,Y) :- temfilho(Y,X).
descendente(X,Y) :- temfilho(Y,Z),!, descendente(X,Y).

avo(X,Y) :- pai(X,Z), temfilho(Z,Y).

primo(X,Y) :- temfilho(A,X), temfilho(B,Y), irmaogenerico(A,B). 

