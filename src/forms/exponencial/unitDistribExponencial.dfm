object FormDistribExponencial: TFormDistribExponencial
  Left = 354
  Top = 121
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Exponencial'
  ClientHeight = 219
  ClientWidth = 451
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 251
    Height = 105
    Caption = 'Dados'
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 32
      Width = 64
      Height = 13
      Caption = 'X                 ='
    end
    object Label2: TLabel
      Left = 30
      Top = 72
      Width = 65
      Height = 13
      Caption = 'Lambda       ='
    end
    object EditX: TEdit
      Left = 124
      Top = 24
      Width = 107
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditLambda: TEdit
      Left = 124
      Top = 64
      Width = 107
      Height = 21
      TabOrder = 1
      Text = '0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 265
    Top = 8
    Width = 177
    Height = 105
    Caption = 'M'#233'todo de c'#225'clulo'
    TabOrder = 1
    object RadioButton2: TRadioButton
      Left = 56
      Top = 57
      Width = 81
      Height = 17
      Caption = 'P ( X > x )'
      TabOrder = 0
    end
    object RadioButton3: TRadioButton
      Left = 56
      Top = 34
      Width = 76
      Height = 17
      Caption = 'P ( X < x )'
      Checked = True
      TabOrder = 1
      TabStop = True
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 119
    Width = 434
    Height = 90
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 30
      Top = 41
      Width = 69
      Height = 13
      Caption = 'Resultado     ='
    end
    object Button1: TButton
      Left = 275
      Top = 28
      Width = 127
      Height = 25
      Caption = 'Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 124
      Top = 33
      Width = 107
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
  end
end
