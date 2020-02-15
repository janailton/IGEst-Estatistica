object FormNormalPadrao: TFormNormalPadrao
  Left = 234
  Top = 131
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Distribui'#231#227'o Normal'
  ClientHeight = 249
  ClientWidth = 458
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
    Width = 265
    Height = 121
    Caption = 'Dados'
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 32
      Width = 85
      Height = 13
      Caption = 'X                        ='
    end
    object Label2: TLabel
      Left = 24
      Top = 59
      Width = 92
      Height = 13
      Caption = 'M'#233'dia                   ='
    end
    object Label3: TLabel
      Left = 24
      Top = 89
      Width = 91
      Height = 13
      Caption = 'Desvio Padr'#227'o     ='
    end
    object EditX: TEdit
      Left = 145
      Top = 29
      Width = 104
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditMedia: TEdit
      Left = 145
      Top = 56
      Width = 104
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object EditDesvioPadrao: TEdit
      Left = 145
      Top = 86
      Width = 104
      Height = 21
      TabOrder = 2
      Text = '0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 279
    Top = 8
    Width = 169
    Height = 121
    Caption = 'M'#233'todo de c'#225'lculo'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 32
      Top = 45
      Width = 113
      Height = 17
      Caption = 'Normal ( X < x )'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 32
      Top = 68
      Width = 113
      Height = 17
      Caption = 'Normal ( X > x )'
      TabOrder = 1
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 135
    Width = 440
    Height = 106
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 24
      Top = 52
      Width = 87
      Height = 13
      Caption = 'Resultado           ='
    end
    object Button1: TButton
      Left = 296
      Top = 40
      Width = 121
      Height = 25
      Caption = 'Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object EditResultado: TEdit
      Left = 145
      Top = 44
      Width = 104
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
  end
end
