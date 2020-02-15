object FHistograma: TFHistograma
  Left = 240
  Top = 59
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Estat'#237'stica Descritiva'
  ClientHeight = 407
  ClientWidth = 771
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenuHistograma
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TabNotebook: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 769
    Height = 401
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'MS Sans Serif'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Dados'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 8
        Width = 297
        Height = 361
        Caption = 'Entrada'
        Color = clBtnFace
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        object Label1: TLabel
          Left = 8
          Top = 24
          Width = 74
          Height = 13
          Caption = 'Insira os dados:'
        end
        object Label2: TLabel
          Left = 8
          Top = 72
          Width = 78
          Height = 13
          Caption = 'Dados inseridos:'
        end
        object Edit1: TEdit
          Left = 8
          Top = 40
          Width = 169
          Height = 21
          TabOrder = 0
          OnKeyDown = Edit1KeyDown
        end
        object ListBox1: TListBox
          Left = 8
          Top = 88
          Width = 169
          Height = 265
          ItemHeight = 13
          MultiSelect = True
          TabOrder = 1
          OnDrawItem = ListBox1DrawItem
        end
        object btnAdicionar: TButton
          Left = 183
          Top = 40
          Width = 111
          Height = 25
          Caption = '&Adicionar'
          TabOrder = 2
          OnClick = btnAdicionarClick
        end
        object btnExcluir: TButton
          Left = 183
          Top = 137
          Width = 111
          Height = 25
          Caption = '&Excluir'
          TabOrder = 3
          OnClick = btnExcluirClick
        end
        object btnCalcular: TButton
          Left = 183
          Top = 72
          Width = 111
          Height = 25
          Caption = '&Calcular'
          TabOrder = 4
          OnClick = btnCalcularClick
        end
        object btnExcluirTudo: TButton
          Left = 183
          Top = 169
          Width = 111
          Height = 25
          Caption = 'E&xcluir Tudo'
          TabOrder = 5
          OnClick = btnExcluirTudoClick
        end
        object btnSalvarnoExcel: TButton
          Left = 183
          Top = 106
          Width = 111
          Height = 25
          Caption = 'Exibir no Excel'
          TabOrder = 6
          OnClick = btnSalvarnoExcelClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 312
        Top = 8
        Width = 449
        Height = 361
        Caption = 'Ajuda'
        Color = clBtnFace
        ParentBackground = False
        ParentColor = False
        TabOrder = 1
        object Memo1: TMemo
          Left = 8
          Top = 16
          Width = 433
          Height = 337
          Lines.Strings = (
            ''
            
              '- Digite um n'#250'mero na caixa de texto logo abaixo da legenda "Ins' +
              'ira dados" ('#224' esquerda) '
            
              'e clique no bot'#227'o "Adicionar" para incluir o n'#250'mero na s'#233'rie de ' +
              'dados a serem '
            
              'processados. Ou, se preferir, digite um n'#250'mero e aperte o bot'#227'o ' +
              '"Enter" no seu teclado '
            
              'para adicionar o n'#250'mero '#224' lista. Repita o processo at'#233' incluir t' +
              'odos os n'#250'meros que deseja '
            'analisar;'
            ''
            '- Quando inserir todos os n'#250'meros, clique no bot'#227'o "Calcular";'
            ''
            
              '- Se n'#227'o houver inconsist'#234'ncia nos dados fornecidos, ser'#225' feito ' +
              'o resumo descritivo dos '
            
              'dados, apresentando a distribui'#231#227'o de frequ'#234'ncia, medidas de ten' +
              'd'#234'ncia central, medidas '
            
              'de dispers'#227'o e histogramas de frequ'#234'ncias nas respectivas abas, ' +
              'logo abaixo do menu '
            'do programa.'
            ''
            
              'Detalhe: s'#243' '#233' poss'#237'vel inserir um n'#250'mero de cada vez. Os n'#250'meros' +
              ' podem ser inteiros'
            'ou reais;'
            ''
            '')
          ReadOnly = True
          TabOrder = 0
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Distribui'#231#227'o de Freq'#252#234'ncia'
      object REDistrFreq: TRichEdit
        Left = 0
        Top = 0
        Width = 761
        Height = 369
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        HideScrollBars = False
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
        Zoom = 100
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Freq'#252#234'ncia Absoluta'
      object ChartFreqAbs: TChart
        Left = 8
        Top = 8
        Width = 745
        Height = 361
        BackWall.Brush.Style = bsClear
        Title.Font.Height = -16
        Title.Text.Strings = (
          'Histograma de Freq'#252#234'ncia Absoluta')
        BottomAxis.Title.Caption = 'Classes'
        BottomAxis.Title.Font.Height = -16
        LeftAxis.Title.Caption = 'Freq'#252#234'ncia Absoluta'
        LeftAxis.Title.Font.Height = -16
        View3D = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object FreqAbs: TBarSeries
          Legend.Visible = False
          Marks.Style = smsValue
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Freq'#252#234'ncia Absoluta Acumulada'
      object ChartFreqAbsAcum: TChart
        Left = 8
        Top = 8
        Width = 745
        Height = 361
        BackWall.Brush.Style = bsClear
        Title.Font.Height = -16
        Title.Text.Strings = (
          'Histograma de Freq'#252#234'ncia Absoluta Acumulada')
        BottomAxis.Title.Caption = 'Classes'
        BottomAxis.Title.Font.Height = -16
        LeftAxis.Title.Caption = 'Freq'#252#234'ncia Absoluta Acumulada'
        LeftAxis.Title.Font.Height = -16
        View3D = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object FreqAbsAcum: TBarSeries
          Legend.Visible = False
          Marks.Style = smsValue
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Freq'#252#234'ncia Relativa'
      object ChartFreqRel: TChart
        Left = 8
        Top = 8
        Width = 745
        Height = 361
        BackWall.Brush.Style = bsClear
        Title.Font.Height = -16
        Title.Text.Strings = (
          'Histograma de Freq'#252#234'ncia Relativa (%)')
        BottomAxis.Title.Caption = 'Classes'
        BottomAxis.Title.Font.Height = -16
        LeftAxis.Title.Caption = 'Freq'#252#234'ncia Relativa'
        LeftAxis.Title.Font.Height = -16
        View3D = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object FreqRel: TBarSeries
          Legend.Visible = False
          Marks.Style = smsValue
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Freq'#252#234'ncia Relativa Acumulada'
      object ChartFreqRelAcum: TChart
        Left = 8
        Top = 8
        Width = 745
        Height = 361
        BackWall.Brush.Style = bsClear
        Title.Font.Height = -16
        Title.Text.Strings = (
          'Histograma de Freq'#252#234'ncia Relativa Acumulada (%)')
        BottomAxis.Title.Caption = 'Classes'
        BottomAxis.Title.Font.Height = -16
        LeftAxis.Title.Caption = 'Freq'#252#234'ncia Relativa Acumalda (%)'
        LeftAxis.Title.Font.Height = -16
        View3D = False
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object FreqRelAcum: TBarSeries
          Legend.Visible = False
          Marks.Style = smsValue
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
  end
  object MainMenuHistograma: TMainMenu
    BiDiMode = bdLeftToRight
    OwnerDraw = True
    ParentBiDiMode = False
    Left = 136
    Top = 448
    object Arquivo1: TMenuItem
      Caption = '&Arquivo'
      object Novo1: TMenuItem
        Caption = '&Novo'
        OnClick = Novo1Click
      end
      object Abrir1: TMenuItem
        Caption = '&Abrir'
        OnClick = Abrir1Click
      end
      object Salvar1: TMenuItem
        Caption = '&Salvar'
        OnClick = Salvar1Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Title = 'Salvar'
    Left = 24
    Top = 24
  end
  object OpenDialog1: TOpenDialog
    Title = 'Abrir'
    Left = 72
    Top = 24
  end
end
