from sys import *

#classe Kmgio
#@param sett: intero, numero della settimana
#@param giorno: lista di stringhe, giorno della settimana
#@param kmp: intero, km percorsi in un giorno

class Kmgio :
    def __init__(self, sett, giorno, kmp) :
        #inizializzo giorni come una lista di stringhe 
        giorni = ['lu', 'ma', 'me', 'gi', 've', 'sa']
        #controllo che il parametro giorno sia di un valore accettabile  
        if giorno > 0 and giorno < 7 :
            self.giorno = giorni[giorno-1]
        else :
            return 'Error'
        #controllo che il parametro giorno sia di un valore accettabile  
        if sett > 0 and sett < 53 :
            self.sett = sett
        else : 
            return 'Error'
        self.kmp = kmp

    
    def __lt__(self, other) :
        return self.sett < other.sett
        
#conversione a stringa
#return descrizione in stringa
    def __repr__(self) -> str:
        return 'Giorno-> ' + str(self.giorno) + ' Settimana -> ' + str(self.settimana) + ' Kmp -> ' + str(self.kmp)


 
#classe fittizia Settimana
#inizializzata con elementi di tipo None
def Sett_init():
    return(Settimana[None]*6)

#@param se: è di tipo Settimana, classe fittizia inizializzata come lista di None
#@param kg: è di tipo Kmgio
#return Bool
def Set_add(se, kg) :
    for i in range(len(se)) :
        if se[i] != None and se[i].sett == kg[i].sett :
            se[i] = kg[i] #sostituisce kg, che è di tipo Kmgio a se
        else :
            return False
    return True

def Anno_acq(nomeFile) :
    l = []                          
    while True :
        line = nomeFile.readline()     
        if not line :            
            break                 
        ls = line.split()          
        l.append(ls)
    l_kmgio = []
    for el in l :
        l_kmgio.append(Kmgio(int(el[0]), el[1], float(el[2])))
    return l_kmgio

#@param sl: lista 
#Ordinamento secondo sett (utilizzo metodo __lt__)
#funzione che restituisce la lista ordinata sl 

def Anno_sort(sl) :
    n = len(sl)
    for i in range(n) :
        min = sl[0]
        tr = False
        for j in range(i+1, n) :
            if sl[j] < min :
                tr = True
                min = sl[i]
                indice_tr = j 
        if tr :
            occ = sl[i]
            sl[i] = sl[indice_tr]
            sl[indice_tr] = occ
    return sl

#sezione di attivazione
def main() :
    if len(sys.argv) < 2 :
        return
    nomeFile = open(sys.argv[1], 'r')
    l = Anno_acq(nomeFile)   
    print(l)    # Visualizzazione del file

    g = []
    for el in l :
        g.append(el.sett)
    print('Settimana con più giorni-> ' + str(statistics.mode(g)))  # Visualizzazione settimana con più giorni

    l = Anno_sort(l)    # Ordinamento
    print(l)

    print("chilometri totalizzati l'ultima settimana-> " + str(l[-1].kmp))  #Visualizzazione chilometri
    
main()