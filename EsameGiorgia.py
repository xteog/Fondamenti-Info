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
        i = giorni.index(giorno)
        if i != -1:
            self.giorno = i + 1
        else :
            return 'Error'
        #controllo che il parametro giorno sia di un valore accettabile  
        if sett > 0 and sett < 53 :
            self.sett = sett
        else : 
            return 'Error'
        self.kmp = kmp

    
    def __lt__(self, other):
        return self.sett < other.sett
        
#conversione a stringa
#return descrizione in stringa
    def __repr__(self) -> str:
        return 'Giorno-> ' + str(self.giorno) + ' Settimana -> ' + str(self.sett) + ' Kmp -> ' + str(self.kmp)


 
#classe fittizia Settimana
#inizializzata con elementi di tipo None
def Sett_init():
    return [None]*6

#@param se: è di tipo Settimana, classe fittizia inizializzata come lista di None
#@param kg: è di tipo Kmgio
#return Bool
def Set_add(se, kg) :
    for i in range(len(se)) :
        if (se[i] != None and se[i].sett != kg.sett) or se[kg.giorno - 1] != None:
            return False, se
    se[kg.giorno - 1] = kg #sostituisce kg, che è di tipo Kmgio a se
    return True, se

def Anno_acq(nomeFile) :
    l = [Sett_init()]                     
    while True :
        line = nomeFile.readline()     
        if not line :            
            break                 
        ls = line.split()
        kmgio = Kmgio(int(ls[0]), ls[1], float(ls[2]))
        i = 0
        response, l[i] = Set_add(l[i], kmgio)
        while not response and i < len(l):
            response, l[i] = Set_add(l[i], kmgio)
            i += 1
        if not response:
            l.append(Sett_init())
            response, l[i] = Set_add(l[i], kmgio)
    return l

#@param sl: lista 
#Ordinamento secondo sett (utilizzo metodo __lt__)
#funzione che restituisce la lista ordinata sl 

def Anno_sort(sl) :
    n = len(sl)
    km = 0
    for i in range(n) :
        check = [sl[0][k] != None for k in range(len(sl))]
        min = sl[0][check.index(True)]
        tr = False
        for j in range(i, n) :
            check = [sl[j][k] != None for k in range(len(sl))]
            k = check.index(True)
            if sl[j][k] < min :
                tr = True
                min = sl[j][k]
                indice_tr = j 
        if tr :
            occ = sl[i]
            sl[i] = sl[indice_tr]
            sl[indice_tr] = occ
        for j in range(6):
            if sl[i][j] != None:
                km += sl[i][j].kmp
    return sl, km

#sezione di attivazione
def main() :
    if len(argv) < 2 :
        return
    nomeFile = open(argv[1], 'r')
    l = Anno_acq(nomeFile)   
    print(l)

    max = 0
    for el in l:
        count = 0
        for obj in el:
            if obj != None:
                count += 1
        if max < count:
            max = count
            max_sett = el
    print(f'Settimana con più giorni-> {max_sett}')
    l_ord, km = Anno_sort(l)    # Ordinamento
    print(l_ord)
    print(km)

    km = 0
    dim = len(l_ord)
    for i in range(6):
        if l_ord[dim-1][i] != None:
            km += l_ord[dim-1][i].kmp
    print(f"chilometri totalizzati l'ultima settimana-> {km}") #Visualizzazione chilometri
    
main()
