class composition:

    
    def _init_(self, produit, quantite):
        self.__produit = produit
        self.__quantite = quantite
    
    @property
    def get_produit(self): 
        return self.__produit
    
    def set_produit(self, newproduit) :
        self.__produit = newproduit

    @property
    def get_quantite(self):
        return self.__quantite
    
    def set_quantite(self, newquantite):
        self.__quantite = newquantite

    
    
    def _str_(self):
        return f"""produit: {self.__produit},quantite: {self.__quantite}"""

    def _eq_(self, other):
        if (self.get_produit == other.get_produit)and(self.get_quantite == other.get_quantite):
            return True
        else:
            return False
            
            
            
from abc import ABCMeta,abstractmethod


class produit(metaclass=ABCMeta):
    def _init_(self, nom,code):
        self.__nom = nom
        self.__code = code
  
    @property

    def get_nom(self):
        return self.__nom
    @property

    def get_code(self):
        return self.__code

    def Set_nom(self, newnom):
        self.__nom = newnom

    def Set_code(self, newcode):
        self.__code = newcode

    def _str_(self):
        return f""" nom: {self.get_nom} ,
                   code: {self.get_code}"""
            
    
    def _eq_(self, other):
        if (self.get_code == other.get_code):
            return True
        else:
            return False
             
    @abstractmethod
    def getprixHt(self):
      pass
            




class Elementaire (produit):
    def _init_(self, nom, code, prixAchat):
        super()._init_(nom, code)
        self.__prixAchat = prixAchat

    @property
    def GetprixAchat (self) :
        return self.__prixAchat
    
    def SetprixAchat (self,prixAchat) :
        self.__prixAchat = prixAchat

    def _str_(self):
        return f"{super()._str_()} purshace price : {str(self.GetprixAchat)}"
     
    def getprixHt(self):
      return super().getprixHt()
  



class Compose(produit):
    def _init_(self,nom,code,fraisFabri,tauxTVA,listeCon ):
        super()._init_(nom, code)
        self.__fraisFabri = fraisFabri
        self.__tauxTVA = 0.18
        self.__listeCon = listeCon
        

    @property
    def GetfraisFabri(self):
        return self.__fraisFabri
        
    def SetfraisFabri(self,newfraisFabrication) :
        self.__fraisFabri = newfraisFabrication

    @property
    def tauxTVA(self):
        return self.__tauxTVA
        
    def SettauxTVA(self,newtauxTVA) :
        self.__tauxTVA=newtauxTVA

    @property
    def GetlisteCon(self):
        return self.__listeCon
        
    def SetlisteCon(self,newlistConstituants) :
        self.__listeCon = newlistConstituants
    
    
    def getliste(self):
        return self.__liste
        
        
    def setliste(self):
        self.__liste = liste 
        
      
      
      
      
    @property
    def _str_(self):
        
        p =''
        for i in range(len (self. GetlisteCon)):
          p += self._listeCon[i].__str_()
        return f"{super()._str_()} Manufacturing costs: {str(self.GetfraisFabri)}; vAt: {str(self.SettauxTVA)}"
        
        
        
    def getprixHt(self):
        prix = 0
        for i in range (len(self.__listeCon)):
          prix += self.__listeCon(i)
        return prix+self.__fraisFabri
     
   



elementaire1=Elementaire("Zara","Fa7362", 374)
ele1 = Elementaire("i","dhsjhss",45)
composition1 = composition(elementaire1,10)
comp2 = composition(ele1,90)
compose1 = Compose("hp","dududg",50,18,[composition1,comp2])

print(ele1)
print(elementaire1)
print(composition1)
print(comp2)
print(composition1 == comp2 )
print(compose1.getprixHt)
